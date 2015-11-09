/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wolfssl_wolfcrypt_Fips */

#ifndef _Included_com_wolfssl_wolfcrypt_Fips
#define _Included_com_wolfssl_wolfcrypt_Fips
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    wolfCrypt_SetCb_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Fips/ErrorCallback;)V
 */
JNIEXPORT void JNICALL Java_com_wolfssl_wolfcrypt_Fips_wolfCrypt_1SetCb_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    wolfCrypt_GetCoreHash_fips
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_wolfssl_wolfcrypt_Fips_wolfCrypt_1GetCoreHash_1fips
  (JNIEnv *, jclass);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesSetKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;I)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesSetKey_1fips__Lcom_wolfssl_wolfcrypt_Aes_2Ljava_nio_ByteBuffer_2JLjava_nio_ByteBuffer_2I
  (JNIEnv *, jclass, jobject, jobject, jlong, jobject, jint);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesSetKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;[BJ[BI)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesSetKey_1fips__Lcom_wolfssl_wolfcrypt_Aes_2_3BJ_3BI
  (JNIEnv *, jclass, jobject, jbyteArray, jlong, jbyteArray, jint);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesSetIV_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesSetIV_1fips__Lcom_wolfssl_wolfcrypt_Aes_2Ljava_nio_ByteBuffer_2
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesSetIV_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;[B)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesSetIV_1fips__Lcom_wolfssl_wolfcrypt_Aes_2_3B
  (JNIEnv *, jclass, jobject, jbyteArray);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesCbcEncrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesCbcEncrypt_1fips__Lcom_wolfssl_wolfcrypt_Aes_2Ljava_nio_ByteBuffer_2Ljava_nio_ByteBuffer_2J
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesCbcEncrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;[B[BJ)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesCbcEncrypt_1fips__Lcom_wolfssl_wolfcrypt_Aes_2_3B_3BJ
  (JNIEnv *, jclass, jobject, jbyteArray, jbyteArray, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesCbcDecrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesCbcDecrypt_1fips__Lcom_wolfssl_wolfcrypt_Aes_2Ljava_nio_ByteBuffer_2Ljava_nio_ByteBuffer_2J
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesCbcDecrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;[B[BJ)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesCbcDecrypt_1fips__Lcom_wolfssl_wolfcrypt_Aes_2_3B_3BJ
  (JNIEnv *, jclass, jobject, jbyteArray, jbyteArray, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesGcmSetKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesGcmSetKey_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesGcmEncrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesGcmEncrypt_1fips
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong, jobject, jlong, jobject, jlong, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    AesGcmDecrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Aes;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_AesGcmDecrypt_1fips
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong, jobject, jlong, jobject, jlong, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Des3_SetKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Des3;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;I)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Des3_1SetKey_1fips
  (JNIEnv *, jclass, jobject, jobject, jobject, jint);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Des3_SetIV_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Des3;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Des3_1SetIV_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Des3_CbcEncrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Des3;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Des3_1CbcEncrypt_1fips
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Des3_CbcDecrypt_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Des3;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Des3_1CbcDecrypt_1fips
  (JNIEnv *, jclass, jobject, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    HmacSetKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Hmac;ILjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_HmacSetKey_1fips
  (JNIEnv *, jclass, jobject, jint, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    HmacUpdate_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Hmac;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_HmacUpdate_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    HmacFinal_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Hmac;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_HmacFinal_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitRng_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rng;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitRng_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    FreeRng_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rng;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_FreeRng_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RNG_GenerateBlock_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rng;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RNG_1GenerateBlock_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RNG_HealthTest_fips
 * Signature: (ILjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RNG_1HealthTest_1fips
  (JNIEnv *, jclass, jint, jobject, jlong, jobject, jlong, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitRsaKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rsa;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitRsaKey_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    FreeRsaKey_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rsa;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_FreeRsaKey_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaSSL_Sign_fips
 * Signature: (Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLcom/wolfssl/wolfcrypt/Rsa;Lcom/wolfssl/wolfcrypt/Rng;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaSSL_1Sign_1fips
  (JNIEnv *, jclass, jobject, jlong, jobject, jlong, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaSSL_Verify_fips
 * Signature: (Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLcom/wolfssl/wolfcrypt/Rsa;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaSSL_1Verify_1fips
  (JNIEnv *, jclass, jobject, jlong, jobject, jlong, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaEncryptSize_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Rsa;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaEncryptSize_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaPrivateKeyDecode_fips
 * Signature: (Ljava/nio/ByteBuffer;[JLcom/wolfssl/wolfcrypt/Rsa;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaPrivateKeyDecode_1fips
  (JNIEnv *, jclass, jobject, jlongArray, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaPublicKeyDecode_fips
 * Signature: (Ljava/nio/ByteBuffer;[JLcom/wolfssl/wolfcrypt/Rsa;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaPublicKeyDecode_1fips
  (JNIEnv *, jclass, jobject, jlongArray, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitSha_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitSha_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ShaUpdate_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ShaUpdate_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ShaFinal_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ShaFinal_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitSha256_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha256;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitSha256_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha256Update_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha256;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha256Update_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha256Final_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha256;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha256Final_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitSha384_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha384;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitSha384_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha384Update_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha384;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha384Update_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha384Final_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha384;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha384Final_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitSha512_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha512;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitSha512_1fips
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha512Update_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha512;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha512Update_1fips
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Sha512Final_fips
 * Signature: (Lcom/wolfssl/wolfcrypt/Sha512;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Sha512Final_1fips
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    wolfCrypt_GetStatus_fips
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_wolfCrypt_1GetStatus_1fips
  (JNIEnv *, jclass);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    wolfCrypt_SetStatus_fips
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_wolfCrypt_1SetStatus_1fips
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaPublicEncrypt_fips
 * Signature: (Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLcom/wolfssl/wolfcrypt/Rsa;Lcom/wolfssl/wolfcrypt/Rng;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaPublicEncrypt_1fips
  (JNIEnv *, jclass, jobject, jlong, jobject, jlong, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    RsaPrivateDecrypt_fips
 * Signature: (Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;JLcom/wolfssl/wolfcrypt/Rsa;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_RsaPrivateDecrypt_1fips
  (JNIEnv *, jclass, jobject, jlong, jobject, jlong, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitMd5
 * Signature: (Lcom/wolfssl/wolfcrypt/Md5;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitMd5
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Md5Update
 * Signature: (Lcom/wolfssl/wolfcrypt/Md5;Ljava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Md5Update
  (JNIEnv *, jclass, jobject, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    Md5Final
 * Signature: (Lcom/wolfssl/wolfcrypt/Md5;Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_Md5Final
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    InitDhKey
 * Signature: (Lcom/wolfssl/wolfcrypt/Dh;)V
 */
JNIEXPORT void JNICALL Java_com_wolfssl_wolfcrypt_Fips_InitDhKey
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    FreeDhKey
 * Signature: (Lcom/wolfssl/wolfcrypt/Dh;)V
 */
JNIEXPORT void JNICALL Java_com_wolfssl_wolfcrypt_Fips_FreeDhKey
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    DhGenerateKeyPair
 * Signature: (Lcom/wolfssl/wolfcrypt/Dh;Lcom/wolfssl/wolfcrypt/Rng;Ljava/nio/ByteBuffer;[JLjava/nio/ByteBuffer;[J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_DhGenerateKeyPair
  (JNIEnv *, jclass, jobject, jobject, jobject, jlongArray, jobject, jlongArray);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    DhAgree
 * Signature: (Lcom/wolfssl/wolfcrypt/Dh;Ljava/nio/ByteBuffer;[JLjava/nio/ByteBuffer;JLjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_DhAgree
  (JNIEnv *, jclass, jobject, jobject, jlongArray, jobject, jlong, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    DhKeyDecode
 * Signature: (Ljava/nio/ByteBuffer;[JLcom/wolfssl/wolfcrypt/Dh;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_DhKeyDecode
  (JNIEnv *, jclass, jobject, jlongArray, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    DhSetKey
 * Signature: (Lcom/wolfssl/wolfcrypt/Dh;Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_DhSetKey
  (JNIEnv *, jclass, jobject, jobject, jlong, jobject, jlong);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    DhParamsLoad
 * Signature: (Ljava/nio/ByteBuffer;JLjava/nio/ByteBuffer;[JLjava/nio/ByteBuffer;[J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_DhParamsLoad
  (JNIEnv *, jclass, jobject, jlong, jobject, jlongArray, jobject, jlongArray);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_init
 * Signature: (Lcom/wolfssl/wolfcrypt/Ecc;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1init
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_free
 * Signature: (Lcom/wolfssl/wolfcrypt/Ecc;)V
 */
JNIEXPORT void JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1free
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_make_key
 * Signature: (Lcom/wolfssl/wolfcrypt/Rng;ILcom/wolfssl/wolfcrypt/Ecc;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1make_1key
  (JNIEnv *, jclass, jobject, jint, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_shared_secret
 * Signature: (Lcom/wolfssl/wolfcrypt/Ecc;Lcom/wolfssl/wolfcrypt/Ecc;Ljava/nio/ByteBuffer;[J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1shared_1secret
  (JNIEnv *, jclass, jobject, jobject, jobject, jlongArray);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_import_x963
 * Signature: (Ljava/nio/ByteBuffer;JLcom/wolfssl/wolfcrypt/Ecc;)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1import_1x963
  (JNIEnv *, jclass, jobject, jlong, jobject);

/*
 * Class:     com_wolfssl_wolfcrypt_Fips
 * Method:    ecc_export_x963
 * Signature: (Lcom/wolfssl/wolfcrypt/Ecc;Ljava/nio/ByteBuffer;[J)I
 */
JNIEXPORT jint JNICALL Java_com_wolfssl_wolfcrypt_Fips_ecc_1export_1x963
  (JNIEnv *, jclass, jobject, jobject, jlongArray);

#ifdef __cplusplus
}
#endif
#endif
