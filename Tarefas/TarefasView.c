#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TarefasView.h"
#include "TarefasController.h"
#include "TarefasModel.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


char tasks_menu(void) {
    char op;
    limpar_tela();
    printf("---------------------------------------------------\n");
    printf("|                      Tarefas                    |\n");
    printf("---------------------------------------------------\n");
    printf("|               [1] Cadastrar Tarefas             |\n");
    printf("|               [2] Exibir Tarefas                |\n");
    printf("|               [3] Editar Tarefas                |\n");
    printf("|               [4] Excluir Tarefas               |\n");
    printf("|               [0] Sair                          |\n");
    printf("--------------------------------------------------\n");
    printf("Informe a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void register_new_task(void) {    
    show_header("Cadastrar Tarefa");

    if(register_task()){
        show_sucess("| Tarefa cadastrada com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao cadastrar!\n");
    }

    enter();
}


void view_task(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    show_header("Exibir Tarefas");
    Tasks *task = malloc(sizeof(Tasks));
    memset(task, 0, sizeof(Tasks));

    limpa_buffer();
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();

    if(load_task(cpf, task)){
        display_data_task(task);
    } else {
        show_error("| Erro ao carregar as tarefas do usuário!\n");
    }

    free(cpf);
    free(task);
    enter(); 
}


void edit_task(void) { // Esta tela antecede a tela -> alterar dados
    show_header("Editar Tarefas");
    Tasks task = {
        .cpf = "111.111.111-11",
        .title = "NOVO TITULO",
        .description = NULL,
        .data = NULL,
        .turn = NULL,
        .priority = NULL,
        .status = NULL
    };
    if(update_title_task(&task)) {
        show_sucess("| Tarefa alterada com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao alterar!\n");
    }
    enter();
}


void delete_task(void) {
    show_header("Excluir Tarefas");
    enter();
}

void display_data_task(Tasks *task){
    show_header("Dados Tarefas");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("| \033[1mTítulo:\033[0m %s\n", task->title);
    printf("| \033[1mCPF:\033[0m %s\n", task->cpf);
    printf("| \033[1mDescrição:\033[0m %s\n", task->description);
    printf("| \033[1mData:\033[0m %s\n", task->data);
    printf("| \033[1mTurno:\033[0m %s\n", task->turn);
    printf("| \033[1mPrioridade:\033[0m %s\n", task->priority);            
    printf("| \033[1mStatus:\033[0m %s\n", task->status);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
