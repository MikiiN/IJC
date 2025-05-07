// ppm.h
// Řešení IJC-DU1, příklad b), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include <limits.h>

struct ppm {
        unsigned int xsize;
        unsigned int ysize;
        char data[];
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

inline void ppm_bitset(char *jmeno, unsigned long index, int vyraz){
        if(vyraz == 0){ 
            *jmeno &= ~(1 << ((index % CHAR_BIT))); 
        } 
        else{ 
            *jmeno |= 1 << ((index % CHAR_BIT)); 
        } 
}

inline int ppm_bitget(char znak){
        return (znak & 1);
}