// htab_free.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// destructor
void htab_free(htab_t * t){
    htab_clear(t);
    free(t->arr_ptr);
    free(t);
}