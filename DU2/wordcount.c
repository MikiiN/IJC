// wordcount.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

#define MAX_WORD_SIZE 255
#define START_TABLE_SIZE 6

// funkce pro výpis
void print_table(htab_pair_t *data){
    printf("%s\t%d\n", data->key, data->value);
}

int main(){
    htab_t *table = htab_init(START_TABLE_SIZE);
    if(table == NULL){
        fprintf(stderr, "Chyba pri alokaci pameti.\n");
        return 1;
    }

    htab_key_t key;
    htab_pair_t *tmp;
    char *word = malloc(sizeof(char) * MAX_WORD_SIZE +1);

    // načtení slova a uložení do tabulky
    int len;
    while((len = read_word(word, MAX_WORD_SIZE+1, stdin)) != -1){
        if(len){
            key = word; 
            tmp = htab_lookup_add(table, key);
            tmp->value++;
        }
    }

    free(word);
    htab_for_each(table, &print_table);

    htab_free(table);
}