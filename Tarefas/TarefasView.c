#include <stdio.h>
void tela_tarefas(void) {
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("|                      Tarefas                    |\n");
    printf("---------------------------------------------------\n");
    printf("|               [1] Cadastrar Tarefas             |\n");
    printf("|               [2] Exibir Trefas                 |\n");
    printf("|               [3] Editar Tarefas                |\n");
    printf("|               [4] Excluir Tarefas               |\n");
    printf("|               [0] Sair                          |\n");
    printf("--------------------------------------------------\n");
}

void cadastrar_tarefas(void){
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|                            Cadastro Tarefas                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data  |  Turno  |  Prioridade  |  Status  |\n");
    printf("-----------------------------------------------------------------------\n");
}

void exibir_tarefas(void){ // Esta tela antecede a tela que exibirá os dados das tarefas
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");
}

void editar_tarefas(void){
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");
}

void excluir_tarefas(void){
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");
}

void dados_tarefas(dados) { // será implementado as variveis de cada dado
    printf("\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados da Tarefa                                                               |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |          Título          |                   Descrição                   |   Data   |  Turno  |    Prioridade    |    Status    |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

