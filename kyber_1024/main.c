#include<stdio.h>
#include"kem.h"





int main() {


	uint8_t pk[PQCLEAN_KYBER1024_CLEAN_CRYPTO_PUBLICKEYBYTES]; 
	uint8_t sk[PQCLEAN_KYBER1024_CLEAN_CRYPTO_SECRETKEYBYTES];
	uint8_t ct[PQCLEAN_KYBER1024_CLEAN_CRYPTO_CIPHERTEXTBYTES]; 
	uint8_t ss[PQCLEAN_KYBER1024_CLEAN_CRYPTO_BYTES];  
	uint8_t ss2[PQCLEAN_KYBER1024_CLEAN_CRYPTO_BYTES];


	PQCLEAN_KYBER1024_CLEAN_crypto_kem_keypair(pk, sk);
	PQCLEAN_KYBER1024_CLEAN_crypto_kem_enc(ct, ss, pk); 
	PQCLEAN_KYBER1024_CLEAN_crypto_kem_dec(ss2, ct, sk);
        
        ss[0]++;
        PQCLEAN_KYBER1024_CLEAN_crypto_kem_enc(ct, ss, pk); 

	return 0;

}

// 30 286 469 -> 22 452 276
