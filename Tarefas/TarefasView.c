#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TarefasView.h"
#include "TarefasController.h"
#include "TarefasModel.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"



/**
 * @brief Função que carrega dados na estrutura.
 * 
 * @param title Ponteiro que é utilizado em show_header.
 * 
 * @return Retorna a estrutura carregada.
 */
Tasks initialize_task(const char *title){
    show_header(title);
    Tasks task = {0};

    limpa_buffer();
    printf("| Informe o ID da tarefa: ");
    char id[3];
    scanf(" %3s", id);

    if(!load_task(id, &task)){
        show_error("| Erro ao carregar as tarefas do usuário!\n");
    }
    return task;
}


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


void view_task(void) {
    Tasks task = initialize_task("Visualizar Tarefas");
    enter();
    free_struct_task(&task);
}


void edit_task(void) {
    Tasks task = initialize_task("Editar Tarefas");

    if(task.cpf != NULL){
        update_task(&task);
    }

    enter();
    free_struct_task(&task);
}


void delete_task(void) {
    show_header("Excluir Tarefas");
    enter();
}


void display_data_task(Tasks *task, int index, const char *id_line) {
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados da tarefa                                                               |\n");
    if(index == 0)printf("| \033[1mCPF:\033[0m %s\n", task->cpf);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("| \033[1mID:\033[0m %s\n", id_line);
    printf("| \033[1mTítulo:\033[0m %s\n", task->title);
    printf("| \033[1mDescrição:\033[0m %s\n", task->description);
    printf("| \033[1mData:\033[0m %s\n", task->data);
    printf("| \033[1mTurno:\033[0m %s\n", task->turn);
    printf("| \033[1mPrioridade:\033[0m %s\n", task->priority);            
    printf("| \033[1mStatus:\033[0m %s\n", task->status);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
