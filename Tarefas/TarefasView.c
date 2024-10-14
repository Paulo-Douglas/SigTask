#include <stdio.h>
#include "TarefasView.h"

char titulo[25];
char descricao[40];
char data[10];
char turno[10];
char prioridade[18];
char status[10];

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
    printf("Informe o titulo dessa tarefa: ");
    scanf("%25", titulo);
    printf("\n");
    printf("Informe a descrição dessa tarefa: ");
    scanf("%40", descricao);
    printf("\n");
    printf("Informe a data para realizar essa tarefa (xx/xx/xxxx): ");
    scanf("%10", data);
    printf("\n");
    printf("Informe o turno de realização dessa tarefa: ");
    scanf("%10", turno);
    printf("\n");
    printf("Informe a prioridade dessa tarefa: ");
    scanf("%18", prioridade);
    printf("\n");
    printf("Informe o status dessa tarefa: ");
    scanf("%10", status);
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
    printf("|                                                            Dados da Tarefa                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |          Título          |                   Descrição                   |    Data   |    Turno   |     Prioridade    |    Status    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void alterar_dados_tarefas(void) {
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                        Alterar Dados da Tarefa                                                                |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |    1   ->   Título       |             2   ->   Descrição                | 3 -> Data | 4 -> Turno |  5 -> Prioridade  | 6 -> Status  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}