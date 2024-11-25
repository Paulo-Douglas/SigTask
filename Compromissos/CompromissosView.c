#include <stdio.h>
#include <stdlib.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


/*************  ✨ Codeium Command ⭐  *************/
/******  a003a083-17b6-4b8a-a6d9-f8508e158f7b  *******/char menu_compromise(void) {
    char op;
    limpar_tela();
    printf("----------------------------------------------------\n");
    printf("|                     Compromissos                 |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Compromisso          |\n");
    printf("|               [2] Exibir Compromisso             |\n");
    printf("|               [3] Editar Compromisso             |\n");
    printf("|               [4] Excluir Compromisso            |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void register_compromises(void) {
    show_header("Cadastrar compromisso");
    enter();
}


void show_compromises(void) { 
    show_header("Exibir compromissos");
    enter();
}    

void edit_compromises(void) { 
    show_header("Editar compromisso");
    enter();

}

void delete_compromises(void) { 
    show_header("Excluir compromisso");
    enter();
}

void data_compromises(void) {
    show_header("Dados do compromisso");
    enter();
}

void change_data_compromisses(void) {
    show_header("Alterar dados do compromisso");
    enter();
}