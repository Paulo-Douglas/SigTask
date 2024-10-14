#include <stdio.h>
#include "TarefasView.h"

char menu_tarefas(void) {
    char op;
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
    printf("Informe a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void cadastrar_tarefas(void) {
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|                            Cadastro Tarefas                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data  |  Turno  |  Prioridade  |  Status  |\n");
    printf("-----------------------------------------------------------------------\n");
}

void exibir_tarefas(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");
}

void editar_tarefas(void) { // Esta tela antecede a tela -> alterar dados
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");
}

void excluir_tarefas(void) { // Esta tela antece a tela que exibirá os dados das tarefas -> a mesma que exibe os dados da tarefa
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");
}

void dados_tarefas(void) { // será implementado as variveis de cada dado
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Dados da Tarefa                                                                 |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |          Título          |                   Descrição                   |    Data   |    Turno   |     Prioridade    |    Status    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void alterar_dados_tarefas(void) {
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Alterar Dados da Tarefa                                                            |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |    1   ->   Título       |             2   ->   Descrição                | 3 -> Data | 4 -> Turno |  5 -> Prioridade  | 6 -> Status  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}