// htab_clear.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// rekurzivně uvolní seznam
void free_items(htab_item_t *item){
    if(item->next != NULL){
        free_items(item->next);
    }
    free((char *)item->data->key);
    free(item->data);
    free(item);
}

void htab_clear(htab_t * t){
    // postupně prochází ukazatele z arr_ptr
    for(int i = 0; i < t->arr_size; i++){
        if(t->arr_ptr[i] != NULL){
            free_items(t->arr_ptr[i]);
            t->arr_ptr[i] = NULL;
        }
    }
    t->size = 0;
}