// primes.c
// Řešení IJC-DU1, příklad a), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "eratosthenes.h"
#include <time.h>

#define N 300000000

int main(){
    clock_t start = clock();
    bitset_create(p, N);
    Eratosthenes(p);

    int count = PRIME_NUMB - 1;
    unsigned long prime_print[PRIME_NUMB] = {0};
    for(bitset_index_t i = bitset_size(p)-1; (count >= 0) && (i > 1); i--){
        if(bitset_getbit(p, i) == 0){
            prime_print[count] = i;
            count--;
        }
    }
    for(int i = 0; i < PRIME_NUMB; i++){
        printf("%ld\n", prime_print[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}