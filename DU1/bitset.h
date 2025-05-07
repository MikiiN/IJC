// bitset.h
// Řešení IJC-DU1, příklad a), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;

#define LONG_BIT (sizeof(long) * CHAR_BIT)
#define UL_ONE (unsigned long)1

#define bitset_create(jmeno_pole, velikost) \
        _Static_assert((velikost) > 0, "Pole nemuze mit zapornou nebo nulovou velikost!\n"); \
        if((velikost) > ULONG_MAX){ \
            fprintf(stderr, "bitset_create: Presazena maximalni velikost pole\n"); \
        } \
        bitset_t (jmeno_pole)[((velikost) / LONG_BIT) + 2] = {0}; \
        (jmeno_pole)[0] = (velikost); \
    

#define bitset_alloc(jmeno_pole, velikost) \
        assert((velikost) < ULONG_MAX); \
        if((velikost) <= 0){ \
            fprintf(stderr, "bitset_alloc: Pole nemuze mit zapornou nebo nulovou velikost!\n"); \
        } \
        bitset_t *jmeno_pole = calloc((velikost / LONG_BIT) + 2, sizeof(long)); \
        jmeno_pole[0] = velikost; \
        if(jmeno_pole == NULL) { \
            error_exit("bitset_alloc: Chyba alokace paměti\n"); \
        } \

#ifdef USE_INLINE

    inline void bitset_free(bitset_t *jmeno_pole){
        free(jmeno_pole);
    }

    inline unsigned long bitset_size(bitset_t *jmeno_pole){
        return jmeno_pole[0];
    }

    inline void bitset_setbit(bitset_t *jmeno_pole, bitset_index_t index, unsigned long vyraz){
        if(index > jmeno_pole[0]){ \
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole)); 
        } 
        if(vyraz == 0){ 
            jmeno_pole[(index / LONG_BIT) + 1] &= ~(UL_ONE << (index % LONG_BIT)); 
        } 
        else{ 
            jmeno_pole[(index / LONG_BIT) + 1] |= UL_ONE << (index % LONG_BIT); 
        } 
    }

    inline int bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index){
        if(index > jmeno_pole[0]){ 
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(jmeno_pole)); 
        } 
        return (jmeno_pole[(index / LONG_BIT) + 1] >> (index % LONG_BIT)) & UL_ONE; 
    }
    
#else

    #define bitset_free(jmeno_pole) do{ \
        free((jmeno_pole)); \
    }while(0)

    #define bitset_size(jmeno_pole)( \
        (jmeno_pole)[0] \
    )

    #define bitset_setbit(jmeno_pole,index,vyraz) do{ \
        if((index) >= (jmeno_pole)[0]){ \
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (index), bitset_size(jmeno_pole)); \
        } \
        if((vyraz) == 0){ \
            (jmeno_pole)[((index) / LONG_BIT) + 1] &= ~(UL_ONE << ((index) % LONG_BIT)); \
        } \
        else{ \
            (jmeno_pole)[((index) / LONG_BIT) + 1] |= UL_ONE << ((index) % LONG_BIT); \
        } \
    }while(0)

    #define bitset_getbit(jmeno_pole,index)( \
        ((index) >= (jmeno_pole[0])) ? \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (index), bitset_size(jmeno_pole)), 0 : \
        ((jmeno_pole[((index) / LONG_BIT) + 1] >> ((index) % LONG_BIT)) & UL_ONE) \
    )

#endif