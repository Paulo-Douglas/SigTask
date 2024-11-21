#include <stdio.h>
#include <stdlib.h>

#include "TarefasView.h"
#include "TarefasController.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


char menu_tarefas(void) {
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

void cadastrar_tarefas(void) {    
    limpar_tela();
    printf("-----------------------------------------------------------------------\n");
    printf("|                            Cadastro Tarefas                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data  |  Turno  |  Prioridade  |  Status  |\n");
    printf("-----------------------------------------------------------------------\n");

    if(register_task()){
        show_sucess("Tarefa cadastrada com sucesso!\n");
    } else {
        show_error("[ERRO]: Erro ao cadastrar!\n");
    }
    limpa_buffer();
    printf("Tecle <ENTER> para continuar...");
    getchar();
}


void exibir_tarefas(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_task_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_tarefas();
        if(!upload_data_task(cpf)){
            show_error("Erro ao carregar as tarefas do usuário!\n");
        }
    }
    free(cpf);
    limpa_buffer(); 
}


void editar_tarefas(void) { // Esta tela antecede a tela -> alterar dados
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_task_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        alterar_dados_tarefas();
        upload_data_task(cpf);
    }   
    free(cpf);
    limpa_buffer(); 

}


void excluir_tarefas(void) {
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_task_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_tarefas();
        if(!upload_data_task(cpf)){
            show_error("Erro ao carregar as tarefas do usuário!\n");
        }
    }   
    free(cpf);
    limpa_buffer(); 
}

void dados_tarefas(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados da Tarefa                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   CPF   |          Título          |                   Descrição                   |    Data   |    Turno   |     Prioridade    |    Status   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void alterar_dados_tarefas(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                        Alterar Dados da Tarefa                                                                |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   CPF   |    1   ->   Título       |             2   ->   Descrição                | 3 -> Data | 4 -> Turno |  5 -> Prioridade  | 6 -> Status |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
