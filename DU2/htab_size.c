// htab_size.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// vrací počet položek v tabulce
size_t htab_size(const htab_t * t){
    return t->size;
}