#include <stdio.h>

#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/styles.h"


void navigation_compromise(void) {
    char op;
    do {
        op = menu_compromise();
        switch(op) {
            case '1':
                register_compromises();
                limpa_buffer();
                break;
            case '2':
                view_compromise();
                limpa_buffer();
                break;
            case '3':
                edit_compromise();
                limpa_buffer();
                break;
            case '4':
                delete_compromises();
                limpa_buffer();
                break;
            case '0':
                break;
            default:
                show_error("Opção inválida, por favor, digite outro número.");
                limpa_buffer();
                break;
        }
    } while (op != '0');
    limpa_buffer();
    limpar_tela();
}