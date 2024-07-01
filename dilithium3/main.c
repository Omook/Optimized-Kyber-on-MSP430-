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
    uint8_t sk[CRYPTO_SECRETKEYBYTES] = { 0 };
    uint8_t m[CRYPTO_MSG_BYTES] = { 0x9E, 0x25, 0x10, 0x3A, 0xA9, 0x89, 0x96, 0xD4, 0x9A, 0xBA, 0x32, 0xB4, 0x1C, 0x0A, 0xFD, 0x62, 0x2B, 0xD6, 0xF2, 0xB7, 0xC9, 0x65, 0x48, 0xE4, 0xF2, 0x14, 0x00, 0xB7, 0xD1, 0xB0, 0xBA, 0x1A };
    uint8_t sig[CRYPTO_BYTES] = { 0 };
    size_t siglen = 0;
    size_t mlen = CRYPTO_MSG_BYTES;
    

    
    crypto_sign_keypair(pk, sk);
    ret = crypto_sign_signature(sig, &siglen, m, mlen, sk);
    ret = crypto_sign_verify(sig, siglen, m, mlen, pk);
    

    ret++;
    //crypto_sign_keypair(pk, sk);

    return ret;
}


//Keygen : 23'961'650
//sign   : 58'810'372