#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#include "utils.h"
#include "../Tarefas/TarefasController.h"

void limpa_buffer(void) {
    int b;
    while((b = getchar()) != '\n' && b != EOF);
}

void enter(void) {
    printf("| Tecle <ENTER> para continuar...");
    limpa_buffer();
}


void limpar_tela(void) {
    system("clear || cls");
}

void create_path(const char *name_path) {
    struct stat path = {0};
    if(stat(name_path, &path) == -1){
        mkdir("data", 0700);
    }
}

int year_now(void) {
    // OpenAI. (2023). ChatGPT (modelo GPT-4)

    time_t t = time(NULL); // Tempo em segundos
    struct tm tm = *localtime(&t); // Tempo local
    int year = tm.tm_year + 1900; // Soma 1900 para obter o ano completo
    return year;
}
