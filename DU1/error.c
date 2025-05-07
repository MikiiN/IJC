// error.c
// Řešení IJC-DU1, příklad b), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include "error.h"

void warning_msg(const char *fmt, ...){
    va_list arg;
    va_start(arg, fmt);
    vfprintf(stderr, "CHYBA: ", 0);
    vfprintf(stderr, fmt, arg);
    va_end(arg);
}

void error_exit(const char *fmt, ...){
    va_list arg;
    va_start(arg, fmt);
    vfprintf(stderr, "CHYBA: ", 0);
    vfprintf(stderr, fmt, arg);
    va_end(arg);
    exit(1);
}