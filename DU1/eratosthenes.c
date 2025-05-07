// eratosthenes.c
// Řešení IJC-DU1, příklad a), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "eratosthenes.h"

void Eratosthenes(bitset_t *pole){
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);
    for(bitset_index_t i = 2; (i * i) < bitset_size(pole); i++){
        if(bitset_getbit(pole, i) == 0){
            for(bitset_index_t j = 2; (j * i) < bitset_size(pole); j++){
                bitset_setbit(pole, (j * i), 1);
            }
        }
    }
}