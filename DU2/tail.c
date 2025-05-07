// tail.c
// Řešení IJC-DU2, příklad a), 14.04.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

// limit velikosti řádků
#define LINE_MAX 4095

// výpis errorů - funkce převzatá z DU1
void error(const char *fmt, ...){
    va_list arg;
    va_start(arg, fmt);
    vfprintf(stderr, "tail: ", 0);
    vfprintf(stderr, fmt, arg);
    va_end(arg);
    exit(1);
}

// načtení argumentů
void load_arg(int *file_index, int *numb, char *arg[], int arg_numb){
    char *is_valid = NULL;
    for (int i = 1; i < arg_numb; i++){
        // načtení jména souboru (uložení indexu)
        if(strcmp("-n", arg[i])){
            *file_index = i;
        }
        else{
            // načítení přepínače -n
            if((i+1) >= arg_numb){
                error("Prepinac \"-n\" vyzaduje parametr.\n");
            }
            i++;
            *numb = strtol(arg[i], &is_valid, 10);
            if(*is_valid != '\0'){
                error("Prepinac \"-n\" vyzaduje cislo.\n");
            }
            if(*numb < 0){
                error("Prepinac \"-n\" vyzaduje kladne cislo.\n");
            }
        }
    }
}

// ukládání posledních n řádků
void add_to_buffer(int buffer_size, char *buffer[], char *line){
    char *tmp = calloc(LINE_MAX+1, sizeof(char));
    strcpy(tmp, line);
    free(buffer[0]);
    for(int i = 0; i < buffer_size-1; i++){
        buffer[i] = buffer[i+1];
    }
    buffer[buffer_size-1] = tmp;
}

int readChar(FILE *file){
    if(file != NULL){
        return fgetc(file);
    }
    else{
        return getchar();
    }
}

void read_lines(FILE *file, int numb, char *buffer[]){
    char line[LINE_MAX+1];
    int c;
    int i = 0;
    bool over = false;
    // čtení řádků
    while ((c = readChar(file)) != EOF){
        // nalezení konce řádku
        if (c == '\n'){
            line[i] = '\0';
            add_to_buffer(numb, buffer, line);
            i = 0;
            continue;
        }
        // kontrola velikosti řádku
        if (i >= LINE_MAX){
            if(!over){
                fprintf(stderr, "tail: Prekrocena maximalni velikost radku (%d). Radky se automaticky zkrati.\n", LINE_MAX);
                over = true;
            }
            // zkrácení řádku
            line[LINE_MAX] = '\0';
            add_to_buffer(numb, buffer, line);
            while ((c = readChar(file)) != '\n'){

            }
            i = 0;
            continue;
        }
        else if(c != '\0'){
            line[i] = c;
            i++;
        }
    }
}

void print_buffer(char *buffer[], int size){
    for(int i = 0; i < size; i++){
        if(buffer[i] != NULL){
            printf("%s\n", buffer[i]);
        }
    }
}

// inicializace bufferu
void buffer_init(char *buffer[], int numb){
    for (int i = 0; i < numb; i++){
        buffer[i] = NULL;
    }
}

void buffer_free(char *buffer[], int numb){
    for (int i = 0; i<numb; i++){
        free(buffer[i]);
    }
}

int main(int argc, char *argv[]){
    // kontrola počtu argumentů
    if (argc > 4){
        error("Prilis mnoho argumentu!\n");
    }

    FILE *file = NULL;
    int file_index = 0;
    int numb_line = 10;
    load_arg(&file_index, &numb_line, argv, argc);
    if(numb_line == 0){
        // -n 0
        return 0;
    }

    char *buffer[numb_line];
    buffer_init(buffer, numb_line);

    // otevření souboru (pokud byl zadán)
    if(file_index != 0){
        file = fopen(argv[file_index], "r");
        if(file == NULL){
            error("Soubor se nepodarilo otevrit.\n");
        }
    }
    read_lines(file, numb_line, buffer);

    if(file != NULL){
        fclose(file);
    }

    print_buffer(buffer, numb_line);
    buffer_free(buffer, numb_line);
}