// error.h
// Řešení IJC-DU1, příklad b), 10.03.2022
// Autor: Michal Žatečka, FIT
// Přeloženo: gcc 9.3.0
// 

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);