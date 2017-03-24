/* WolfCryptCipher.java
 *
 * Copyright (C) 2006-2017 wolfSSL Inc.
 *
 * This file is part of wolfSSL. (formerly known as CyaSSL)
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

package com.wolfssl.provider.jce;

import java.util.Arrays;

import javax.crypto.Cipher;
import javax.crypto.CipherSpi;
import javax.crypto.SecretKey;
import javax.crypto.BadPaddingException;
import javax.crypto.ShortBufferException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;

import java.security.SecureRandom;
import java.security.AlgorithmParameters;
import java.security.spec.AlgorithmParameterSpec;
import java.security.spec.InvalidParameterSpecException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;

import com.wolfssl.wolfcrypt.WolfCrypt;
import com.wolfssl.wolfcrypt.Asn;
import com.wolfssl.wolfcrypt.Aes;
import com.wolfssl.wolfcrypt.Des3;
import com.wolfssl.wolfcrypt.Rsa;
import com.wolfssl.wolfcrypt.Rng;

/**
 * wolfCrypt JCE Cipher (AES, 3DES) wrapper
 *
 * @author wolfSSL
 * @version 1.0, March 2017
 */
public class WolfCryptCipher extends CipherSpi {

    enum CipherType {
        WC_AES,
        WC_DES3,
        WC_RSA
    }

    enum CipherMode {
        WC_ECB,
        WC_CBC
    }

    enum PaddingType {
        WC_NONE,
        WC_PKCS1
    }

    enum OpMode {
        WC_ENCRYPT,
        WC_DECRYPT
    }

    enum RsaKeyType {
        WC_RSA_PRIVATE,
        WC_RSA_PUBLIC
    }

    private CipherType cipherType   = null;
    private CipherMode cipherMode   = null;
    private PaddingType paddingType = null;
    private OpMode direction        = null;
    private RsaKeyType rsaKeyType   = null;

    private int blockSize = 0;

    private Aes  aes  = null;
    private Des3 des3 = null;
    private Rsa  rsa  = null;

    /* stash IV here for easy lookup */
    private byte[] iv = null;

    private WolfCryptCipher(CipherType type, CipherMode mode,
            PaddingType pad) {

        this.cipherType = type;
        this.cipherMode = mode;
        this.paddingType = pad;

        switch (cipherType) {
            case WC_AES:
                aes = new Aes();
                blockSize = Aes.BLOCK_SIZE;
                break;

            case WC_DES3:
                des3 = new Des3();
                blockSize = Des3.BLOCK_SIZE;
                break;

            case WC_RSA:
                rsa = new Rsa();
                break;
        }
    }

    @Override
    protected void engineSetMode(String mode)
        throws NoSuchAlgorithmException {

        int supported = 0;

        if (mode.equals("ECB")) {

            /* RSA is ECB mode */
            if (cipherType == CipherType.WC_RSA) {
                cipherMode = CipherMode.WC_ECB;
                supported = 1;
            }

        } else if (mode.equals("CBC")) {

            /* AES and 3DES support CBC */
            if (cipherType == CipherType.WC_AES ||
                cipherType == CipherType.WC_DES3 ) {
                cipherMode = CipherMode.WC_CBC;
                supported = 1;
            }
        }

        if (supported == 0) {
            throw new NoSuchAlgorithmException(
                "Unsupported cipher mode for active algorithm choice");
        }
    }

    @Override
    protected void engineSetPadding(String padding)
        throws NoSuchPaddingException {

        int supported = 0;

        if (padding.equals("NoPadding")) {

            if (cipherType == CipherType.WC_AES ||
                cipherType == CipherType.WC_DES3) {
                paddingType = PaddingType.WC_NONE;
                supported = 1;
            }

        } else if (padding.equals("PKCS1Padding")) {

            if (cipherType == CipherType.WC_RSA) {
                paddingType = PaddingType.WC_PKCS1;
                supported = 1;
            }
        }
        
        if (supported == 0) {
            throw new NoSuchPaddingException(
                "Unsupported padding type for active algorithm choice");
        }
    }

    @Override
    protected int engineGetBlockSize() {
        return this.blockSize;
    }

    @Override
    protected int engineGetOutputSize(int inputLen) {

        int size = 0;

        switch (this.cipherType) {
            case WC_AES:
            case WC_DES3:
                /* wolfCrypt expects input to be padded by application to
                 * block size, thus output is same size as input */
                size = inputLen;
                break;

            case WC_RSA:
                size = this.rsa.getEncryptSize();
                break;
        }

        return size;
    }

    @Override
    protected byte[] engineGetIV() {
        return this.iv;
    }

    @Override
    protected AlgorithmParameters engineGetParameters() {
        /* not currently supported by wolfCrypt JCE provider */
        return null;
    }

    private void wolfCryptSetDirection(int opmode)
        throws InvalidKeyException {

        /* we don't currently support AES key wrap in JCE yet,
         * so don't allow WRAP_MODE or UNWRAP_MODE */
        switch (opmode) {
            case Cipher.ENCRYPT_MODE:
                this.direction = OpMode.WC_ENCRYPT;
                break;

            case Cipher.DECRYPT_MODE:
                this.direction = OpMode.WC_DECRYPT;
                break;

            default:
                throw new InvalidKeyException(
                    "Cipher opmode must be ENCRYPT_MODE or DECRPYT_MODE");
        }
    }

    private void wolfCryptSetIV(AlgorithmParameterSpec spec,
            SecureRandom random) throws InvalidAlgorithmParameterException {

        /* RSA doesn't need an IV */
        if (this.cipherType == CipherType.WC_RSA)
            return;

        /* store IV, or generate random IV if not available */
        if (spec == null) {
            if (random != null) {
                random.nextBytes(this.iv);
            } else {
                SecureRandom rand = new SecureRandom();
                rand.nextBytes(this.iv);
            }
        } else {
            if (!(spec instanceof IvParameterSpec)) {
                throw new InvalidAlgorithmParameterException(
                    "AlgorithmParameterSpec must be of type IvParameterSpec");
            }

            IvParameterSpec ivSpec = (IvParameterSpec)spec;
            this.iv = ivSpec.getIV();
        }
    }

    private void wolfCryptSetKey(Key key)
        throws InvalidKeyException {

        int ret = 0;
        long[] idx = {0};
        byte[] encodedKey;

        /* validate key class type */
        if (this.cipherType == CipherType.WC_RSA) {

            if (key instanceof RSAPrivateKey) {
                this.rsaKeyType = RsaKeyType.WC_RSA_PRIVATE;

            } else if (key instanceof RSAPublicKey) {
                this.rsaKeyType = RsaKeyType.WC_RSA_PUBLIC;

            } else {
                throw new InvalidKeyException(
                    "Cipher key must be of type RSAPrivateKey or " +
                    "RSAPublicKey when used for RSA encrypt or decrypt");
            }

        } else if (!(key instanceof SecretKey)) {
            throw new InvalidKeyException(
                "Cipher key must be of type SecretKey");
        }

        /* import key */
        encodedKey = key.getEncoded();
        if (encodedKey == null)
            throw new InvalidKeyException("Key does not support encoding");

        switch (cipherType) {
            case WC_AES:
                if (this.direction == OpMode.WC_ENCRYPT) {
                    this.aes.setKey(encodedKey, iv, Aes.ENCRYPT_MODE);
                } else {
                    this.aes.setKey(encodedKey, iv, Aes.DECRYPT_MODE);
                }
                break;

            case WC_DES3:
                if (this.direction == OpMode.WC_ENCRYPT) {
                    this.des3.setKey(encodedKey, iv, Des3.ENCRYPT_MODE);
                } else {
                    this.des3.setKey(encodedKey, iv, Des3.DECRYPT_MODE);
                }
                break;

            case WC_RSA:

                /* reset key struct if needed */
                if (this.rsa != null)
                    this.rsa.releaseNativeStruct();

                this.rsa = new Rsa();

                if (this.rsaKeyType == RsaKeyType.WC_RSA_PRIVATE) {

                    this.rsa.decodePrivateKeyPKCS8(encodedKey);

                } else {
                    this.rsa.decodePublicKey(encodedKey);
                }
                break;
        }
    }

    /* called by engineInit() functions */
    private void wolfCryptCipherInit(int opmode, Key key,
            AlgorithmParameterSpec spec, SecureRandom random)
        throws InvalidKeyException, InvalidAlgorithmParameterException {

        wolfCryptSetDirection(opmode);
        wolfCryptSetIV(spec, random);
        wolfCryptSetKey(key);
    }

    @Override
    protected void engineInit(int opmode, Key key, SecureRandom random)
        throws InvalidKeyException {

        try {

            wolfCryptCipherInit(opmode, key, null, random);

        } catch (InvalidAlgorithmParameterException iape) {
            throw new InvalidKeyException("Invalid algorithm parameters");
        }
    }

    @Override
    protected void engineInit(int opmode, Key key,
            AlgorithmParameterSpec params, SecureRandom random)
        throws InvalidKeyException, InvalidAlgorithmParameterException {

        wolfCryptCipherInit(opmode, key, params, random);
    }

    @Override
    protected void engineInit(int opmode, Key key,
            AlgorithmParameters params, SecureRandom random)
        throws InvalidKeyException, InvalidAlgorithmParameterException {

        AlgorithmParameterSpec spec;

        try {

            spec = params.getParameterSpec(IvParameterSpec.class);

        } catch (InvalidParameterSpecException ipe) {
            throw new InvalidAlgorithmParameterException(ipe);
        }

        wolfCryptCipherInit(opmode, key, spec, random);
    }

    /* return 1 if this is a block cipher, otherwise 0 */
    private int isBlockCipher() {

        int isBlockCipher = 0;

        switch (this.cipherType) {
            case WC_AES:
            case WC_DES3:
                isBlockCipher = 1;
                break;
            default:
                isBlockCipher = 0;
        };

        return isBlockCipher;
    }

    /* return 1 if cipher is a block cipher and lenth is a block
     * length multiple, otherwise 0 */
    private int isValidBlockLength(int length) {

        /* skip if not a block cipher */
        if (isBlockCipher() == 0)
            return 1;

        if ((length % this.blockSize) != 0)
            return 0;

        return 1;
    }

    private byte[] wolfCryptUpdate(byte[] input, int inputOffset,
            int inputLen) {

        int ret = 0;

        byte tmpIn[]  = Arrays.copyOfRange(input, inputOffset,
                            inputOffset + inputLen);
        byte tmpOut[] = null;

        /* return null if input data is too short to result in a new
         * block, and algorithm is a block cipher */
        if (input == null || isValidBlockLength(inputLen) == 0)
            return null;

        switch (this.cipherType) {

            case WC_AES:
                tmpOut = this.aes.update(input, inputOffset, inputLen);
                break;

            case WC_DES3:
                tmpOut = this.des3.update(input, inputOffset, inputLen);
                break;

            case WC_RSA:

                if (this.direction == OpMode.WC_ENCRYPT) {
                    if (this.rsaKeyType == RsaKeyType.WC_RSA_PRIVATE) {

                        tmpOut = this.rsa.sign(tmpIn, null);
                    } else {

                        Rng rng = new Rng();
                        rng.init();
                        tmpOut = this.rsa.encrypt(tmpIn, rng);
                        rng.free();
                        rng.releaseNativeStruct();
                    }

                } else {
                    if (this.rsaKeyType == RsaKeyType.WC_RSA_PRIVATE) {
                        tmpOut = this.rsa.decrypt(tmpIn);
                    } else {
                        tmpOut = this.rsa.verify(tmpIn);
                    }
                }
                break;

            default:
                throw new RuntimeException("Unsupported algorithm type");
        };

        return tmpOut;
    }

    @Override
    protected byte[] engineUpdate(byte[] input, int inputOffset, int inputLen) {

        byte output[];
        
        output = wolfCryptUpdate(input, inputOffset, inputLen);

        return output;
    }

    @Override
    protected int engineUpdate(byte[] input, int inputOffset, int inputLen,
            byte[] output, int outputOffset)
        throws ShortBufferException {

        byte tmpOut[];

        tmpOut = wolfCryptUpdate(input, inputOffset, inputLen);

        if ((output.length - outputOffset) < tmpOut.length) {
            throw new ShortBufferException(
                "Output buffer too small for encrypted output");
        }

        System.arraycopy(tmpOut, 0, output, outputOffset, tmpOut.length);

        return tmpOut.length;
    }

    private void zeroArray(byte[] in) {

        if (in == null)
            return;

        for (int i = 0; i < in.length; i++) {
            in[i] = 0;
        }
    }

    @Override
    protected byte[] engineDoFinal(byte[] input, int inputOffset,
            int inputLen)
        throws IllegalBlockSizeException, BadPaddingException {

        return engineUpdate(input, inputOffset, inputLen);
    }

    @Override
    protected int engineDoFinal(byte[] input, int inputOffset,
            int inputLen, byte[] output, int outputOffset)
        throws ShortBufferException, IllegalBlockSizeException,
               BadPaddingException {

        return engineUpdate(input, inputOffset, inputLen, output,
                           outputOffset);
    }

    @Override
    protected int engineGetKeySize(Key key)
        throws InvalidKeyException {

        byte encodedKey[] = null;

        /* validate key class type */
        if (this.cipherType == CipherType.WC_RSA) {

            if (key instanceof RSAPrivateKey) {
                this.rsaKeyType = RsaKeyType.WC_RSA_PRIVATE;

            } else if (key instanceof RSAPublicKey) {
                this.rsaKeyType = RsaKeyType.WC_RSA_PUBLIC;

            } else {
                throw new InvalidKeyException(
                    "Cipher key must be of type RSAPrivateKey or " +
                    "RSAPublicKey when used for RSA encrypt or decrypt");
            }

        } else if (!(key instanceof SecretKey)) {
            throw new InvalidKeyException(
                "Cipher key must be of type SecretKey");
        }

        encodedKey = key.getEncoded();
        if (encodedKey == null)
            throw new InvalidKeyException("Key does not support encoding");

        return encodedKey.length;
    }

    @Override
    protected void finalize() throws Throwable {
        try {
            this.aes.releaseNativeStruct();
            this.des3.releaseNativeStruct();

            this.rsa.releaseNativeStruct();

            zeroArray(this.iv);

        } finally {
            super.finalize();
        }
    }

    public static final class wcAESCBCNoPadding extends WolfCryptCipher {
        public wcAESCBCNoPadding() {
            super(CipherType.WC_AES, CipherMode.WC_CBC, PaddingType.WC_NONE);
        }
    }
    public static final class wcDESedeCBCNoPadding extends WolfCryptCipher {
        public wcDESedeCBCNoPadding() {
            super(CipherType.WC_DES3, CipherMode.WC_CBC, PaddingType.WC_NONE);
        }
    }
    public static final class wcRSAECBPKCS1Padding extends WolfCryptCipher {
        public wcRSAECBPKCS1Padding() {
            super(CipherType.WC_RSA, CipherMode.WC_ECB, PaddingType.WC_PKCS1);
        }
    }
}

