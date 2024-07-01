#include <stdio.h>
#include <stdint.h>
#include "api.h"
#include "params.h"
#include <stdlib.h>
#include <time.h>
#define CRYPTO_MSG_BYTES 32
 
int ret = 0;

int main()
{
    uint8_t pk[CRYPTO_PUBLICKEYBYTES] = { 0 };
    //uint8_t sk[CRYPTO_SECRETKEYBYTES] = { 0 };
    uint8_t m[CRYPTO_MSG_BYTES] = { 0x81, 0x80, 0x8D, 0x3C, 0xDE, 0x5B, 0x67, 0xA9, 0xE3, 0xA7, 0xB3, 0x71, 0xC5, 0x93, 0x78, 0xD2, 0xD8, 0xF6, 0xB7, 0x11, 0x5E, 0xDB, 0xE9, 0x1C, 0x9C, 0x3D, 0xA9, 0x6F, 0x34, 0x0F, 0xAD, 0x34 };
    uint8_t sig[CRYPTO_BYTES] = { 0 };
    size_t siglen = 0;
    size_t mlen = CRYPTO_MSG_BYTES;
        
    
    //crypto_sign_keypair(pk, sk);
    //ret = crypto_sign_signature(sig, &siglen, m, mlen, sk);           
    ret = crypto_sign_verify(sig, siglen, m, mlen, pk);

    ret++;
    //crypto_sign_keypair(pk, sk);
    
    return ret;
}
