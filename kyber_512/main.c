
#include "io430.h"
#include "kem.h"

#include "ntt.h"
#include "params.h"
#include "poly.h"
#include "polyvec.h"
//#include "../../../common/randombytes.h"
#include "symmetric.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "poly.h"
#include "fips202.h"
#define KYBER_Q 3329

void change(uint64_t *a, uint64_t *b){
  int cnt = 0;
  int cnt2 = 0;
  for(int i=0;i<5;i++){
    b[i+cnt2] = a[i*5+cnt];    
  }
  cnt+=1;
  cnt2+=5;
  for(int i=0;i<5;i++){
    b[i+cnt2] = a[i*5+cnt];    
  }
  cnt+=1;
  cnt2+=5;
  for(int i=0;i<5;i++){
    b[i+cnt2] = a[i*5+cnt];    
  }
  cnt+=1;
  cnt2+=5;
  for(int i=0;i<5;i++){
    b[i+cnt2] = a[i*5+cnt];    
  }
  cnt+=1;
  cnt2+=5;
  for(int i=0;i<5;i++){
    b[i+cnt2] = a[i*5+cnt];    
  }
  
  for(int i=0;i<25;i++){
    a[i] = b[i];
  }
  
}

int main( void )
{
//  uint64_t A[25];
//  uint64_t B[25];
//  uint64_t t[25];
//  uint64_t b[5];
//  
//  for(int i=0;i<25;i++){
//    A[i] = i;
//  }
//  
//  
//  
//  //change(A,B);  
//  asm_keccak1600(A, t, b);
//  
//  for(int i=0;i<5;i++){
//    printf("%d : %llx\n", i, b[i]);
//  }
//  
//  for(int i=0;i<25;i++){
//    printf("%d : %llx\n", i, A[i]);
//  }
//
//  return 0;
  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  uint8_t pk[PQCLEAN_KYBER512_CLEAN_CRYPTO_PUBLICKEYBYTES]={0,}; // 4,480,052 
  uint8_t sk[PQCLEAN_KYBER512_CLEAN_CRYPTO_SECRETKEYBYTES]={0,};// 
  uint8_t ct[PQCLEAN_KYBER512_CLEAN_CRYPTO_CIPHERTEXTBYTES]; //(2*320)+128
  uint8_t ss[PQCLEAN_KYBER512_CLEAN_CRYPTO_BYTES];  //32
  uint8_t ss2[PQCLEAN_KYBER512_CLEAN_CRYPTO_BYTES];

        
  PQCLEAN_KYBER512_CLEAN_crypto_kem_keypair(pk, sk); //Alice: gen(pk, sk)                          
  
//  for(int i=0;i<PQCLEAN_KYBER512_CLEAN_CRYPTO_PUBLICKEYBYTES;i++){
//          printf("%d : %d\n", i, pk[i]);
//        }
//        for(int i=0;i<PQCLEAN_KYBER512_CLEAN_CRYPTO_SECRETKEYBYTES;i++){
//          printf("%d : %d\n", i, sk[i]);
//        }
  PQCLEAN_KYBER512_CLEAN_crypto_kem_enc(ct, ss, pk); //Alice->Bob:pk, Bob: gen(pk->(ss,ct))           
  PQCLEAN_KYBER512_CLEAN_crypto_kem_dec(ss2, ct, sk);//Bob->Alice:ct, Alice: gen(ct->(ss2))             
  
  printf("\nSS : "); //8 854 149 -> 8 262 789 -> 8 165 235
  for (int i = 0; i < 32; i++) {
	printf("%02X ", ss[i]);
  }

  printf("\nSS2 : ");
  for (int i = 0; i < 32; i++) {
	printf("%02X ", ss2[i]);
  }
//  
//  PQCLEAN_KYBER512_CLEAN_crypto_kem_enc(ct, ss, pk);
  
  return 0;
}

//11 855 359
//11 445 140
//9 500 662

//14 922 665
//18 316 193
//12 163 427


//9 866 448


//9 500 662
//9 493 054
//9 400 000

//9 218 976
//9 203 360
//9 202 848 
//9 199 008
//9 196 856


//12 163 427 -> 8 994 104