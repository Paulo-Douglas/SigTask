#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TarefasController.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


char menu_task(void) {
    char op;
    limpar_tela();
    printf("|---------------------------------------------------|\n");
    printf("|                     Tarefas                       |\n");
    printf("|---------------------------------------------------|\n");
    printf("|               [1] Cadastrar Tarefa                |\n");
    printf("|               [2] Exibir Tarefa                   |\n");
    printf("|               [3] Editar Tarefa                   |\n");
    printf("|               [4] Excluir Tarefa                  |\n");
    printf("|               [0] Sair                            |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void add_task(void) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                              Cadastrar Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    if(register_task()){
        show_sucess("| Tarefa cadastrado com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao cadastrar!\n");
    }

    enter();
}

void search_task(void) {
    limpa_buffer();
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Exibir Tarefa                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    printf("|\tInforme o ID: ");
    char id[4];
    scanf("%4s", id);

    Task *task = load_task(id);
    if(task != NULL){
        display_data_task(task);
    } else show_error("Tarefa não encontrado");

    enter();
}


void change_task(void) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Editar Tarefa                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    printf("|\tInforme o ID: ");
    char id[4];
    scanf("%4s", id);

    Task *task = load_task(id);
    if(task != NULL){
        display_data_task(task);
        edit_task(task);
    } else show_error("Tarefa não encontrado");


    enter();
}


void delete_task(void) { 
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Fechar Tarefa                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    enter();

    printf("|\tInforme o ID: ");
    char id[4];
    scanf("%4s", id);

    Task *task = load_task(id);
    if(task == NULL) show_error("Tarefa não encontrado");
    else if (task->status == '0') show_error("Tarefa ja fechado");
    else {
        task->status = '0';
        update_task(task);
        show_sucess("Tarefa fechado com sucesso!");
    }

    enter();
}


void display_data_task(Task *task){
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados do Tarefa                                                          |\n");
    printf("| \033[1mID:\033[0m %s\n", task->id);
    printf("| \033[1mID do Usuário/Time:\033[0m %s\n", task->responsible);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\033[1m\tTarefa:\033[m %s\n", task->title);
    printf("|\033[1m\tDescrição:\033[m %s\n", task->description);
    printf("|\033[1m\tData:\033[m %s\n", task->date);
    printf("|\033[1m\tPrioridade:\033[m %s\n", task->priority == 'A' ? "Alta" : task->type == 'M' ? "Média" : "Baixa");
    printf("|\033[1m\tTipo:\033[m %s\n", task->type == 'E' ? "Evento" : task->type == 'R' ? "Reunião" : "Projeto");
    printf("|\033[1m\tStatus:\033[0m %s\n", task->status == '0' ? "Aberta" : "Fechada");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

