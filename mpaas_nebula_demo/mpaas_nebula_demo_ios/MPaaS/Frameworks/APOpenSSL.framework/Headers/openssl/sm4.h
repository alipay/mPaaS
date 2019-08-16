#ifndef SM4_HEADER_H
#define SM4_HEADER_H

#include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_SM2

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <openssl/evp.h>

#define SM4_KEY_LENGTH           16
#define SM4_BLOCK_SIZE           16
#define SM4_IV_LENGTH            SM4_BLOCK_SIZE
#define SM4_NUM_ROUNDS           32

#define SM4_ENCRYPT              1
#define SM4_DECRYPT              0

#pragma pack(1)
struct sm4_key_st
{
    uint32_t key[SM4_NUM_ROUNDS];   /*SOFT ALGORITHM*/
};
#pragma pack()
typedef struct sm4_key_st SM4_KEY;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
    int SM4_set_key(const unsigned char *userKey, size_t length, SM4_KEY *key);

    void SM4_encrypt(const unsigned char *in, unsigned char *out, const SM4_KEY *key);
    void SM4_decrypt(const unsigned char *in, unsigned char *out, const SM4_KEY *key);

    void SM4_ecb_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, const int enc);
    void SM4_cbc_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, unsigned char *ivec, const int enc);
    void SM4_cfb_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, unsigned char *ivec, int *num, const int enc);
    void SM4_cfb1_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, unsigned char *ivec, int *num, const int enc);
    void SM4_cfb8_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, unsigned char *ivec, int *num, const int enc);
    void SM4_ofb_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM4_KEY *key, unsigned char *ivec, int *num);
    
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OPENSSL_NO_SM4

#endif // SM4_HEADER_H


