#include <stdio.h>
#include <stdlib.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


Compromisers initialize_compromisse(const char* title){
    show_header(title);
    Compromisers compromise = {0};

    limpa_buffer();
    printf("|\tTime: ");
    char time[4];
    scanf(" %s", time);
    printf("|\t(1) Aberto | (2) Fechado: ");
    char status[2];
    scanf(" %s", status);

    if(!load_compromise(&compromise, time, status)){
        show_error("| [ERRO]: Erro ao carregar compromisso!\n");
    }
    return compromise;
}


char menu_compromise(void) {
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
    Compromisers compromisse = initialize_compromisse("Exibir Compromisso");
    if (compromisse.team_id != 0) show_sucess("<- Compromisso carregado com sucesso! ->");
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
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados do compromisso                                                          |\n");
    if (line_number == 0) printf("\033[1m\tEQUIPE:\033[m %d\n", compromise->team_id);

    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("\033[1m\tCOMPROMISSO:\033[m %s\n", compromise->title);
    printf("\033[1m\tDESCRICAO:\033[m %s\n", compromise->description);
    printf("\033[1m\tDATA DE INICIO:\033[m %s\n", compromise->start_date);
    printf("\033[1m\tDATA DE FIM:\033[m %s\n", compromise->end_date);
    printf("\033[1m\tHORARIO:\033[m %s\n", compromise->time);
    printf("\033[1m\tPRIORIDADE:\033[m %s\n", compromise->priority);
    printf("\033[1m\tSTATUS:\033[m %s\n", compromise->status);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}