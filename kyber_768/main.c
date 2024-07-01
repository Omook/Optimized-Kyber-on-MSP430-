#include<stdio.h>
#include"kem.h"





int main() {
	

	uint8_t pk[PQCLEAN_KYBER768_CLEAN_CRYPTO_PUBLICKEYBYTES]; // (2*384) + 32
	uint8_t sk[PQCLEAN_KYBER768_CLEAN_CRYPTO_SECRETKEYBYTES];// (2*384) + ((2*384) + 32) + 2*32
	uint8_t ct[PQCLEAN_KYBER768_CLEAN_CRYPTO_CIPHERTEXTBYTES]; //(2*320)+128
	uint8_t ss[PQCLEAN_KYBER768_CLEAN_CRYPTO_BYTES];  //32
	uint8_t ss2[PQCLEAN_KYBER768_CLEAN_CRYPTO_BYTES];




	PQCLEAN_KYBER768_CLEAN_crypto_kem_keypair(pk, sk); //Alice: gen(pk, sk) 
	PQCLEAN_KYBER768_CLEAN_crypto_kem_enc(ct, ss, pk); //Alice->Bob:pk, Bob: gen(pk->(ss,ct))
	PQCLEAN_KYBER768_CLEAN_crypto_kem_dec(ss2, ct, sk);//Bob->Alice:ct, Alice: gen(ct->(ss2))
													
        ss[0]++;
        PQCLEAN_KYBER768_CLEAN_crypto_kem_enc(ct, ss, pk); //Alice->Bob:pk, Bob: gen(pk->(ss,ct))
	return 0;

}


