// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// funkce pro přidání nové položky
htab_pair_t *add_item(htab_t *t, htab_key_t key){
    // index arr_ptr nové položky
    size_t index = htab_hash_function(key) % t->arr_size;
    // vytvoření nové položky
    htab_item_t *new = calloc(1, sizeof(htab_item_t));
    if(new == NULL){
        return NULL;
    }
    new->data = calloc(1, sizeof(htab_pair_t));
    if(new->data == NULL){
        return NULL;
    }
    char *new_str = malloc(strlen(key)+1);
    if(new_str == NULL){
        return NULL;
    }

    strcpy(new_str, key);
    new->data->key = new_str;
    new->data->value = 0;
    new->next = NULL;

    // posun na konec seznamu a přidání položky
    htab_item_t *tmp = t->arr_ptr[index];
    if(tmp != NULL){
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    else{
        t->arr_ptr[index] = new;
    }
    t->size++;

    // kontrola, zda průměr položek/velikost arr_size nepřesáhne AVG_LEN_MAX
    int avg = t->size/t->arr_size;
    if(avg > AVG_LEN_MAX){
        htab_resize(t, 2*t->arr_size);
    }

    return htab_find(t, key);
}

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    htab_pair_t *item = htab_find(t, key);

    if(item != NULL){
        return item;
    }
    return add_item(t, key);
}