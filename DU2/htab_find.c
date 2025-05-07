// htab_find.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    // výpočet indexu, aby se nebylo třeba procházet celé pole
    size_t index = htab_hash_function(key) % t->arr_size;

    // průchod seznamem
    for(htab_item_t *j = t->arr_ptr[index]; j != NULL; j=j->next){
        if(!strcmp(j->data->key, key)){
            return j->data;
        }
    }
    return NULL;
}