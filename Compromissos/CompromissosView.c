#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"



Compromisers initialize_compromisse(const char* title){
    show_header(title);
    Compromisers compromise = {0};

    limpa_buffer();
    printf("|\tID: ");
    char id[3];
    scanf(" %s", id);
    printf("|\t(1) Aberto | (2) Fechado: ");
    char status[2];
    scanf(" %s", status);

    if(!load_compromise(id ,&compromise)){
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
    show_header("Cadastrar Compromisso");

    if(register_compromise()){
        show_sucess("| Compromisso cadastrado com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao cadastrar!\n");
    }

    enter();
}

void view_compromise(void) {
    show_header("Exibir compromisso");

    Compromisers compromise = {0};
    printf("|\tInforme o ID do compromisso: ");
    char id[2];
    scanf(" %1s", id);

    if(!load_compromise(id, &compromise)) show_error("| Compromisso não encontrada!\n");
    else display_data_compromises(&compromise);
    printf("\n");

    enter();
}
void edit_compromise(void) {
    show_header("Editar compromissos");

    Compromisers compromise = {0};
    printf("|\tInforme o ID do compromisso: ");
    char id[2];
    scanf(" %1s", id);

    if(!load_compromise(id, &compromise)) show_error("| Compromisso não encontrada!\n");
    else {
        display_data_compromises(&compromise);
        if(update_compromise(&compromise, id)) {
            show_sucess("| Compromisso editado com sucesso!\n");
        } else {
            show_error("| [ERRO]: Erro ao editar!\n");
        }
    }
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
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Alterar compromisso                                                           |\n");
    printf("\033[1m|\t (1) Título\033[0m\n");
    printf("\033[1m|\t (2) Descrição\033[0m\n");
    printf("\033[1m|\t (3) Data de Início\033[0m\n");
    printf("\033[1m|\t (4) Data de Fim\033[0m\n");
    printf("\033[1m|\t (5) Horário\033[0m\n");
    printf("\033[1m|\t (6) Prioridade\033[0m\n");
    printf("\033[1m|\t (7) Status [FECHAR] \033[0m\n");
    printf("\033[1m|\t (8) Status [REABRIR] \033[0m\n");
}

void display_data_compromises(Compromisers *compromise){
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados do compromisso                                                          |\n");
    printf("| \033[1mID:\033[0m %s\n", compromise->team_id);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("\033[1m\tCompromisso:\033[m %s\n", compromise->title);
    printf("\033[1m\tDescrição:\033[m %s\n", compromise->description);
    printf("\033[1m\tData de inicio:\033[m %s\n", compromise->start_date);
    printf("\033[1m\tData de fim:\033[m %s\n", compromise->end_date);
    printf("\033[1m\tHorário:\033[m %s\n", compromise->time);
    printf("| \033[1mPrioridade:\033[0m %s\n", strcmp(compromise->priority, "1") ? "Alta" : (strcmp(compromise->priority, "2") ? "Média" : "Baixa"));  
    printf("| \033[1mStatus:\033[0m %s\n", strcmp(compromise->status, "0") ? "Aberta" : "Fechada");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

