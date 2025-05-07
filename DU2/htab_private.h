// htab_private.h
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

// při testech vyšel nejlepší poměr velikost/rychlost
#define AVG_LEN_MAX 6
#define AVG_LEN_MIN 2

#include <stdint.h>
#include <stdlib.h>
#include "htab.h"

struct htab_item {
    htab_pair_t *data;
    htab_item_t *next;
};

struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};