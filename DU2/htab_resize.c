// htab_resize.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

// funkce pro uvolnění původního **arr_ptr
void free_item(htab_item_t * item){
    if(item->next != NULL){
        free_item(item->next);
    }
    free((char *)item->data->key);
    free(item->data);
    free(item);
}

void free_arr(htab_item_t **arr, size_t size){
    for(int i = 0; i < size ; i++){
        if(arr[i] != NULL){
            free_item(arr[i]);
        }
    }
    free(arr);
}

void htab_resize(htab_t *t, size_t newn){
    // alokace nového arr_ptr
    htab_item_t **new_arr_ptr = calloc(newn, sizeof(htab_item_t *));
    int new_size = t->size;

    // překopírování původního arr_ptr do nového
    htab_item_t *tmp = NULL;
    for(int i = 0; i < t->arr_size; i++){
        tmp = t->arr_ptr[i];
        // procházení seznamu a překopírování každé položky
        while(tmp != NULL){
            // index položky v novém arr_ptr
            size_t index = htab_hash_function(tmp->data->key) % newn;
            htab_item_t *newtmp = new_arr_ptr[index];
            // nová položka pro nakopírování
            htab_item_t *new_item = calloc(1 ,sizeof(htab_item_t));
            if(new_item == NULL){
                free_arr(new_arr_ptr, newn);
                free_item(new_item);
                return;
            }
            new_item->data = calloc(1, sizeof(htab_pair_t));
            if(new_item->data == NULL){
                free_arr(new_arr_ptr, newn);
                free_item(new_item);
                return;
            }
            new_item->data->key = calloc(strlen(tmp->data->key)+1, sizeof(char));
            if(new_item->data->key == NULL){
                free_arr(new_arr_ptr, newn);
                free_item(new_item);
                return;
            }
            // nakopírování položky
            strcpy((char *)new_item->data->key, tmp->data->key);
            new_item->data->value = tmp->data->value;

            if(newtmp != NULL){
                // přidání položky na konec seznamu
                while(newtmp->next != NULL){
                    newtmp = newtmp->next;
                }
                newtmp->next = new_item;

            }
            else{
                // pokud je položka první
                new_arr_ptr[index] = new_item;
            }
            tmp = tmp->next;
        }
    }

    // uvolnění původního arr_ptr
    free_arr(t->arr_ptr, t->arr_size);

    // nahrazení původního arr_ptr novým
    t->arr_ptr = new_arr_ptr;
    t->arr_size = newn;
    t->size = new_size;
}