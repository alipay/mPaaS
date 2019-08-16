#ifndef SM3_HEADER_H
#define SM3_HEADER_H

#include <openssl/opensslconf.h>
#include <stddef.h>

#ifndef OPENSSL_NO_SM2

#define SM3_DIGEST_LENGTH   32
#define SM3_LBLOCK          16
#define SM3_CBLOCK          64
#define SM3_LONG            unsigned int
#define SM3_LONG_LOG2       2

struct SM3state_st
{
    SM3_LONG digest[8];
    SM3_LONG Nl, Nh;
    SM3_LONG data[SM3_LBLOCK];
    unsigned int num;
    int hdev;    
};

typedef struct SM3state_st SM3_CTX;

#ifdef __cplusplus
extern "C"
{
#endif
    int SM3_Init(SM3_CTX *c);
    int SM3_Update(SM3_CTX *c, const void *data, size_t len);
    int SM3_Final(unsigned char *md, SM3_CTX *c);
    unsigned char *SM3(const unsigned char *d, size_t n, unsigned char *md);
    void SM3_Transform(SM3_CTX *c, const unsigned char *data);
#ifdef __cplusplus
}
#endif

#endif // OPENSSL_NO_SM2
    
#endif // !SM3_HEADER_H

