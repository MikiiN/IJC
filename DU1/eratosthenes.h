// eratosthenes.h
// Řešení IJC-DU1, příklad a), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "bitset.h"

#define PRIME_NUMB 10

void Eratosthenes(bitset_t *pole);

#ifdef USE_INLINE
    inline void bitset_free(bitset_t *jmeno_pole);
    inline unsigned long bitset_size(bitset_t *jmeno_pole);
    inline void bitset_setbit(bitset_t *jmeno_pole, bitset_index_t index, unsigned long vyraz);
    inline int bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index);
#endif