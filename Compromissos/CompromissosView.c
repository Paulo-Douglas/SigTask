#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


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
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                              Cadastrar compromisso                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    if(register_compromise()){
        show_sucess("| Compromisso cadastrado com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao cadastrar!\n");
    }

    enter();
}

void view_compromise(void) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Exibir compromisso                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    printf("|\tInforme o ID: ");
    char id[4];
    scanf("%4s", id);

    Compromisers *compromise = load_compromise(id);
    if(compromise != NULL){
        display_data_compromises(compromise);
    } else show_error("Compromisso não encontrado");

    enter();
}


void edit_compromise(void) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Editar compromisso                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    // Compromisers compromise = {0};
    // printf("|\tInforme o ID do compromisso: ");
    // char id[2];
    // scanf(" %1s", id);

    // if(!load_compromise(id, &compromise)) show_error("| Compromisso não encontrada!\n");
    // else {
    //     display_data_compromises(&compromise);
    //     if(update_compromise(&compromise, id)) {
    //         show_sucess("| Compromisso editado com sucesso!\n");
    //     } else {
    //         show_error("| [ERRO]: Erro ao editar!\n");
    //     }
    // }
    enter();
}


void delete_compromises(void) { 
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Fechar compromisso                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    enter();
}


void change_data_compromisses(void) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Alterar compromisso                                                           |\n");
    printf("\033[1m|\t (1) Título\033[0m\n");
    printf("\033[1m|\t (2) Situação\033[0m\n");
    printf("\033[1m|\t (3) Data\033[0m\n");
    printf("\033[1m|\t (3) Descrição\033[0m\n");
    printf("\033[1m|\t (7) Status [FECHAR] \033[0m\n");
    printf("\033[1m|\t (8) Status [REABRIR] \033[0m\n");
}

void display_data_compromises(Compromisers *compromise){
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados do compromisso                                                          |\n");
    printf("| \033[1mID:\033[0m %s\n", compromise->id);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\033[1m\tCompromisso:\033[m %s\n", compromise->title);
    printf("|\033[1m\tDescrição:\033[m %s\n", compromise->description);
    printf("|\033[1m\tData:\033[m %s\n", compromise->date);
    printf("|\033[1m\tPrioridade:\033[m %s\n", compromise->priority == 'A' ? "Alta" : compromise->type == 'M' ? "Média" : "Baixa");
    printf("|\033[1m\tTipo:\033[m %s\n", compromise->type == 'E' ? "Evento" : compromise->type == 'R' ? "Reunião" : "Projeto");
    printf("|\033[1m\tStatus:\033[0m %s\n", compromise->status == '0' ? "Aberta" : "Fechada");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

