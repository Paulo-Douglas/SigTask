#include <stdio.h>
#include "TarefasView.h"
#include "../libs/utils.h"

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
    // Variáveis agora estão no escopo da função
    char titulo[25];
    char descricao[40];
    char data[10];
    char turno[10];
    char prioridade[18];
    char status[10];
    
    limpar_tela();
    printf("-----------------------------------------------------------------------\n");
    printf("|                            Cadastro Tarefas                         |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data  |  Turno  |  Prioridade  |  Status  |\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Informe o titulo dessa tarefa: ");
    scanf("%24s", titulo); // Corrigido para %24s para evitar overflow
    printf("\n");
    printf("Informe a descrição dessa tarefa: ");
    scanf("%39s", descricao); // Corrigido para %39s para evitar overflow
    printf("\n");
    printf("Informe a data para realizar essa tarefa (xx/xx/xxxx): ");
    scanf("%9s", data); // Corrigido para %9s para evitar overflow
    printf("\n");
    printf("Informe o turno de realização dessa tarefa: ");
    scanf("%9s", turno); // Corrigido para %9s para evitar overflow
    printf("\n");
    printf("Informe a prioridade dessa tarefa: ");
    scanf("%17s", prioridade); // Corrigido para %17s para evitar overflow
    printf("\n");
    printf("Informe o status dessa tarefa: ");
    scanf("%9s", status); // Corrigido para %9s para evitar overflow
}

void exibir_tarefas(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    dados_tarefas();
}

void editar_tarefas(void) { // Esta tela antecede a tela -> alterar dados
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    alterar_dados_tarefas();
}

void excluir_tarefas(void) { // Esta tela antece a tela que exibirá os dados das tarefas -> a mesma que exibe os dados da tarefa
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    dados_tarefas();
}

void dados_tarefas(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados da Tarefa                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |          Título          |                   Descrição                   |    Data   |    Turno   |     Prioridade    |    Status    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void alterar_dados_tarefas(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                        Alterar Dados da Tarefa                                                                |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |    1   ->   Título       |             2   ->   Descrição                | 3 -> Data | 4 -> Turno |  5 -> Prioridade  | 6 -> Status  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}
