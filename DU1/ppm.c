// ppm.c
// Řešení IJC-DU1, příklad b), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "ppm.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 8000*8000*3

extern inline void ppm_bitset(char *jmeno, unsigned long index, int vyraz);
extern inline int ppm_bitget(char znak);

struct ppm * ppm_read(const char * filename){
    FILE *file;

    file = fopen(filename, "r");
    if(file == NULL){
        warning_msg("Chyba pri otevreni souboru.\n");
        fclose(file);
        return NULL;
    }

    int width;
    int height;
    int color;
    char format[3];
    if(fscanf(file, "%s %d %d %d\n", format, &width, &height, &color) <= 3){
        warning_msg("Hlavicku souboru se nepodarilo nacist\n");
        fclose(file);
        return NULL;
    }

    if(strcmp(format, "P6")){
        warning_msg("Soubor neni formatu P6\n");
        fclose(file);
        return NULL;
    }

    unsigned long size = width * height * 3;
    if(size > MAX_SIZE){
        warning_msg("Rozmery obrazku prekrocili maximalni hodnotu %ld.\n", MAX_SIZE);
        fclose(file);
        return NULL;
    }

    struct ppm *image = malloc(sizeof(struct ppm) + size);
    image->xsize = width;
    image->ysize = height;

    if(fread(image->data, sizeof(char), size, file) == size){
        fclose(file);
        return image;
    }
    else{
        warning_msg("Chyba pri nacitani dat.\n");
        fclose(file);
        return NULL;
    }
}

void ppm_free(struct ppm *p){
    free(p);
}