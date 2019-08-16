#ifndef SM2_HEADER_H
#define SM2_HEADER_H

#include <stddef.h>
#include <openssl/opensslconf.h>
#include <openssl/evp.h>
#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/ecdh.h>
#include <openssl/ecdsa.h>
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif // !OPENSSL_NO_ENGINE

# ifndef OPENSSL_NO_SM2

struct sm2dh_data_st
{
    int server;       /*server side flag, 0 -- client side; other -- server side*/
    int checksum;     /*calculate check sum tag, 0 -- don't checksum; other  -- checksum*/
    int r_len;        /*private key length, and this is a tag for self data filled*/
    int Rp_len;       /*peer key agreement data filled tag*/
    int Rs_len;       /*self key agreement data*/
    unsigned char r[64];      /*Generated private key, MAX to 512 bits*/
    unsigned char Rs[129];    /*self public key, MAX to 512 bits + 1 tag*/
    unsigned char Rp[129];    /*peer public key, MAX to 512 bits + 1 tag*/
    unsigned char s_checksum[EVP_MAX_MD_SIZE];    /*send checksum*/
    unsigned char e_checksum[EVP_MAX_MD_SIZE];    /*ensure checksum*/
    int peerid_len;    /*ID length*/
    int selfid_len;    /*ID length*/
    unsigned char peer_id[64];    /*ID*/
    unsigned char self_id[64];    /*ID*/
};

typedef struct sm2dh_data_st SM2DH_DATA;

struct sm2enc_st
{
    ASN1_INTEGER *x;
    ASN1_INTEGER *y;
    ASN1_OCTET_STRING *m;
    ASN1_OCTET_STRING *c;
};

typedef struct sm2enc_st SM2ENC;

#  ifdef __cplusplus
extern "C"
{
#  endif // __cplusplus
    int KDF_X9_63(unsigned char *out, size_t outlen, const unsigned char *Z, size_t Zlen, const unsigned char *SharedInfo, size_t SharedInfolen, const EVP_MD *md);
    int ECDSA_sm2_get_Z(const EC_KEY *ec_key, const EVP_MD *md, const char *uid, int uid_len, unsigned char *z_buf, size_t *z_len);
    /*SM2 Sign*/
    ECDSA_SIG *sm2_do_sign(const unsigned char *dgst, int dgst_len, const BIGNUM *in_kinv, const BIGNUM *in_r, EC_KEY *eckey);
    int sm2_do_verify(const unsigned char *dgst, int dgst_len, const ECDSA_SIG *sig, EC_KEY *eckey);
    /*SM2 Encrypt And Decrypt*/
    int sm2_encrypt(unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen, const EVP_MD *md, EC_KEY *ec_key);
    int sm2_decrypt(unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen, const EVP_MD *md, EC_KEY *ec_key);
    int old_sm2_encrypt(unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen, const EVP_MD *md, EC_KEY *ec_key);
    int old_sm2_decrypt(unsigned char *out, size_t *outlen, const unsigned char *in, size_t inlen, const EVP_MD *md, EC_KEY *ec_key);
    /*SM2 DH*/
    int SM2DH_get_ex_data_index(void);
    int SM2DH_set_ex_data(EC_KEY *ecKey, void *datas);
    void *SM2DH_get_ex_data(EC_KEY *ecKey);
    int SM2DH_prepare(EC_KEY *ecKey, int server, unsigned char *R, size_t *R_len);
    int SM2DH_compute_key(void *out, size_t outlen, const EC_POINT *pub_key, EC_KEY *eckey, void *(*KDF) (const void *in, size_t inlen, void *out, size_t *outlen));
    int SM2DH_get_ensure_checksum(void *out, EC_KEY *eckey);
    int SM2DH_get_send_checksum(void *out, EC_KEY *eckey);
    int SM2Kap_compute_key(void *out, size_t outlen, int server, \
        const char *peer_uid, int peer_uid_len, const char *self_uid, int self_uid_len, \
        const EC_KEY *peer_ecdhe_key, const EC_KEY *self_ecdhe_key, const EC_KEY *peer_pub_key, const EC_KEY *self_eckey, \
        const EVP_MD *md);
    int i2d_sm2_enc(const unsigned char *in, size_t inlen, unsigned char **out);
    int d2i_sm2_enc(const unsigned char *in, size_t inlen, unsigned char **out);

#  ifdef __cplusplus
}
#  endif // __cplusplus
# endif // OPENSSL_NO_SM2

#endif // !SM2_HEADER_H



