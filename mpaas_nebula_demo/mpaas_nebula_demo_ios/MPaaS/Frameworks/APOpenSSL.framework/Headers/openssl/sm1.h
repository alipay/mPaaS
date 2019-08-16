#ifndef SM1_HEADER_H
#define SM1_HEADER_H

#include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_SM2

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <openssl/evp.h>

#define SM1_KEY_LENGTH			16
#define SM1_BLOCK_SIZE			16
#define SM1_IV_LENGTH			SM1_BLOCK_SIZE
#define SM1_NUM_ROUNDS			32

#define SM1_ENCRYPT				1
#define SM1_DECRYPT				0

#pragma pack(1)
struct sm1_key_st
{
    uint32_t key[SM1_NUM_ROUNDS];   /*SOFT ALGORITHM*/
};
#pragma pack()
typedef struct sm1_key_st SM1_KEY;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	int SM1_set_key(const unsigned char *userKey, size_t length, SM1_KEY *key);

	void SM1_encrypt(const unsigned char *in, unsigned char *out, const SM1_KEY *key);
	void SM1_decrypt(const unsigned char *in, unsigned char *out, const SM1_KEY *key);

	void SM1_ecb_encrypt(const unsigned char *in, unsigned char *out, const SM1_KEY *key, const int enc);
	void SM1_cbc_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM1_KEY *key, unsigned char *ivec, const int enc);
	void SM1_cfb_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM1_KEY *key, unsigned char *ivec, int *num, const int enc);
	void SM1_cfb1_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM1_KEY *key, unsigned char *ivec, int *num, const int enc);
	void SM1_cfb8_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM1_KEY *key, unsigned char *ivec, int *num, const int enc);
	void SM1_ofb_encrypt(const unsigned char *in, unsigned char *out, size_t length, const SM1_KEY *key, unsigned char *ivec, int *num);
	
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OPENSSL_NO_SM2

#endif // SM1_HEADER_H


