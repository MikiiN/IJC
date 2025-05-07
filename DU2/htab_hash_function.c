// htab_hash_function.c
// IJC-DU2, příklad b), 14.04.2022
// funkce převzatá ze zadání
// Přeloženo: gcc 9.3.0

#include "htab.h"
#include "htab_private.h"

size_t htab_hash_function(htab_key_t str){
    uint32_t h=0;
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h; 
}