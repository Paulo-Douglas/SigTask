#include <stdio.h>
#include "CompromissosView.h"

void navegação_compromissos(void) {
    char op;
    do {
        op = menu_compromissos();
        switch(op) {
            case '1':
                cadastrar_compromissos();
                break;
            case '2':
                exibir_compromissos();
                break;
            case '3':
                editar_compromissos();
                break;
            case '4':
                excluir_compromissos();
                break;
            default:
                printf("Opção inválida, por favor, digite outro número.");
                break;
        }
    } while (op != '0');
}