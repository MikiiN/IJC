// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// vrátí velikost pole
size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}