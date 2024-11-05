#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void limpa_buffer(void) {
    int b;
    while((b = getchar()) != '\n' && b != EOF) {

    }
}

void exibir_menssagem(char *menssagem) {
    printf("%s\n\n", menssagem);
    printf("Tecle <ENTER> para continuar...");
    getchar();
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