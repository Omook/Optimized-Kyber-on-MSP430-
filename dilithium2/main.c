#include <stdio.h>
#include <stdint.h>
#include "api.h"
#include "params.h"
#include "poly.h"
#include "reduce.h"
#include <stdlib.h>
#include <time.h>
#define CRYPTO_MSG_BYTES 32


/*************************************************
 * polyvec.c : asm_pointwise
 *
 * Description: Load 8 bytes into uint64_t in little-endian order
 *
 * Arguments:   - const uint8_t *x: pointer to input byte array
 *
 * Returns the loaded 64-bit unsigned integer
 **************************************************/
int ret = 0;

int main()
{
      
    //data model : small, medium or high 쓰면 오류남
  
    uint8_t pk[CRYPTO_PUBLICKEYBYTES] = { 0 };
    uint8_t sk[CRYPTO_SECRETKEYBYTES] = { 0 };                    
    uint8_t m[CRYPTO_MSG_BYTES] = { 0x94, 0x6A, 0xBC, 0xF4, 0xAE, 0x8E, 0x35, 0x1B, 0xC8, 0xD1, 0xFC, 0x5B, 0x89, 0x4C, 0x91, 0xC7, 0x08, 0xC8, 0x6E, 0x7E, 0x34, 0x8B, 0x8D, 0x25, 0x74, 0x72, 0x2B, 0x95, 0x8A, 0x40, 0xCC, 0xD0};
    uint8_t sig[CRYPTO_BYTES] = { 0 };
    size_t siglen = 0;
    size_t mlen = CRYPTO_MSG_BYTES;
    
    ret = CRYPTO_PUBLICKEYBYTES;
    
    crypto_sign_keypair(pk, sk); 
    ret =crypto_sign_signature(sig, &siglen, m, mlen, sk);
    ret =  crypto_sign_verify(sig, siglen, m, mlen, pk);
    
    //ret++;      
  

    
    //crypto_sign_keypair(pk, sk);    
//    ret =  crypto_sign_verify(sig, siglen, m, mlen, pk);
//    
//    ret++;
//    ret = crypto_sign_signature(sig, &siglen, m, mlen, sk);
    

    //crypto_sign_keypair(pk, sk);
    
    return ret;
}

//ref(midium)
//key pair : 15 132 906
//sign     : 25 666 069
//verify   : 15 892 098

//opti(high_speed)
//key pair : 11 492 565 (+%)
//sign     : 17 351 666 (+%)
//verify   : 11 533 084 (+%)





// 56 713 139 , 15 132 906
// 73 005 080,  20 034 762
// 50 589 687,  13 840 475


// 41 848 051  , 11 962 872
// 42 763 163  ,12 250 292            









































































































































