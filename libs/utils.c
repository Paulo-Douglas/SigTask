#include <stdio.h>

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