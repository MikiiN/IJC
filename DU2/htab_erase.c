// htab_erase.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

bool htab_erase(htab_t * t, htab_key_t key){
    // výpočet indexu aby nebylo třeba procházet celé pole
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *tmp = t->arr_ptr[index];
    htab_item_t *old = NULL;

    // průchod seznamem
    while(tmp != NULL){
        // hledání položky
        if(!strcmp(tmp->data->key, key)){
            htab_item_t *erase = tmp; // uložení ukazatele pro free()

            // rozlišení, jestli je položka první, nebo někde v seznamu
            if(old == NULL){
                t->arr_ptr[index] = tmp->next;
            }
            else{
                old->next = tmp->next;
            }

            // uvolnění paměti odstraněné položky
            free((char *)erase->data->key);
            free(erase->data);
            free(erase);
            t->size--;

            // kontrola jestli průměr se nedostal pod minimální hranici
            int avg = t->size/t->arr_size;
            if(avg < AVG_LEN_MIN){
                htab_resize(t, t->arr_size/2);
            }
            return true; 
        }
        old = tmp;
        tmp = tmp->next;
    }
    // položka nebyla nalezena
    return false;
}