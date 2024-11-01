#include <stdio.h>
#include "styles.h"


void show_error(const char *message) {
    printf("\033[1;31m[ERRO] %s\033[0m\n", message);
}

void show_sucess(const char *message) {
    printf("\033[1;32m[SUCESSO] %s\033[0m\n", message);
}
