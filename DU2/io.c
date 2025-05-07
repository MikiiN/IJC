// io.c
// Řešení IJC-DU2, příklad b), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include "io.h"
#include <ctype.h>
#include <stdbool.h>

bool isOver = false;

int read_word(char *s, int max, FILE *f){
    int c;
    int i = 0;
    // čtení ze souboru
    while((c = fgetc(f)) != EOF){
        // nalezen konec slova
        if(isspace(c)){
            s[i] = '\0';
            return i;
        }
        else{
            // kontrola, zda slovo nepřesáhlo maximální délku
            if(i > (max-1)){
                if(!isOver){
                    isOver = true;
                    fprintf(stderr, "Presazena maximalni delka slova (%d znaku). Slova se automaticky zkrati.\n", max);
                }
                // přeskočení zbytku slova
                while(c != EOF){
                    if(isspace(c)){
                        break;
                    }
                    c = fgetc(f);
                }

                s[i] = '\0';
                return i;
            }

            s[i] = c;
            i++;
        }
    }
    // konec souboru
    return -1;
}