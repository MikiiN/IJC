// htab_init.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

htab_t *htab_init(size_t n){
    htab_t *new = malloc(sizeof(htab_t));
    if(new == NULL){
        return NULL;
    }
    new->arr_ptr = malloc(sizeof(htab_item_t *)*n);
    // kontrola mallocu
    if(new->arr_ptr == NULL){
        return NULL;
    }

    // inicializace tabulky
    new->arr_size = n;
    new->size = 0;
    for(int i = 0; i < n; i++){
        new->arr_ptr[i] = NULL;
    }
    return new;
}