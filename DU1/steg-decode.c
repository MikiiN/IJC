// steg-decode.c
// Řešení IJC-DU1, příklad b), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "ppm.h"
#include "eratosthenes.h"

int main(int argc, char **argv){
    if(argc != 2){
        warning_msg("Spatny pocet argumentu.\n");
        return 1;
    }
    char *name = argv[1];
    struct ppm *image = ppm_read(name);

    if(image == NULL){
        ppm_free(image);
        error_exit("");
    }

    bitset_alloc(primes, (image->xsize * image->ysize * 3));
    Eratosthenes(primes);

    char secretMsg = 0;
    unsigned int count = 0;
    char *rgb = image->data;
    for(bitset_index_t i = 29; i < bitset_size(primes); i++){
        if(bitset_getbit(primes, i) == 0){
            ppm_bitset(&secretMsg, count, ppm_bitget(rgb[i]));
            count++;
            if((count % (CHAR_BIT)) == 0){
                if(secretMsg == '\0'){
                    printf("\n");
                    bitset_free(primes);
                    ppm_free(image);
                    return 0;
                }
                printf("%c", secretMsg);
                count = 0;
            } 
        }
    }
    
    bitset_free(primes);
    ppm_free(image);
    error_exit("Zprava neni korektne ukoncena znakem \0.\n");
}