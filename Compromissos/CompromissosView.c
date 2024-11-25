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
    register_compromise() ? show_sucess("| Compromisso cadastrado com sucesso!\n") : show_error("| [ERRO]: Erro ao cadastrar!\n");
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

void display_data_compromises(Compromisers *compromise, int line_number){
    show_header("Dados do compromisso");
    if (line_number == 0) printf("\033[1mEQUIPE:\033[ %d\n", compromise->team_id);

    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("\033[1mCOMPROMISSO:\033[ %s\n", compromise->title);
    printf("\033[1mDESCRICAO:\033[ %s\n", compromise->description);
    printf("\033[1mDATA DE INICIO:\033[ %s\n", compromise->start_date);
    printf("\033[1mDATA DE FIM:\033[ %s\n", compromise->end_date);
    printf("\033[1mHORARIO:\033[ %s\n", compromise->time);
    printf("\033[1mPRIORIDADE:\033[ %s\n", compromise->priority);
    printf("\033[1mSTATUS:\033[ %s\n", compromise->status);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}