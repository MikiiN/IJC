// bitset.c
// Řešení IJC-DU1, příklad a), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "bitset.h"

#ifdef USE_INLINE

    extern inline void bitset_free(bitset_t *jmeno_pole);

    extern inline unsigned long bitset_size(bitset_t *jmeno_pole);

    extern inline void bitset_setbit(bitset_t *jmeno_pole, bitset_index_t index, unsigned long vyraz);

    extern inline int bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index);

#endif