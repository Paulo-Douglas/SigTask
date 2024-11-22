#include <stdio.h>
#include "styles.h"


void show_error(const char *message) {
    printf("\033[1;31m[ERRO] %s\033[0m\n", message);
}

void show_sucess(const char *message) {
    printf("\033[1;32m[SUCESSO] %s\033[0m\n", message);
}

void show_header(const char *title) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|%*s%*s|\n", (int)(50 + strlen(title) / 2), title, (int)(49 - strlen(title) / 2), "");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}
