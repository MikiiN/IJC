// htab_for_each.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    // průchod celým polem
    for(int i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->arr_ptr[i];
        // průchod seznamem a volání funkce na každou položku
        while(tmp != NULL){
            (*f)(tmp->data);
            tmp = tmp->next;
        }
    }
}