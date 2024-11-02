#include <stdio.h>

#include "TarefasView.h"
#include "TarefasController.h"

#include "../libs/utils.h"
#include "../libs/reads.h"

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
    
    printf("Informe o titulo dessa tarefa: ");
    read_title();
    
    printf("Informe a descrição dessa tarefa: ");
    read_description();
    
    printf("Informe a data para realizar essa tarefa (xx/xx/xxxx): ");
    read_date();
    
    printf("Informe o turno de realização dessa tarefa: ");
    read_date();
    
    printf("Informe a prioridade dessa tarefa: ");
    read_priority();
    
    printf("Informe o status dessa tarefa: ");
    read_status();
}

void exibir_tarefas(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");

    printf("Informe seu CPF: ");
    read_cpf();

    dados_tarefas();
}

void editar_tarefas(void) { // Esta tela antecede a tela -> alterar dados
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");

    printf("Informe seu CPF: ");
    read_cpf();

    alterar_dados_tarefas();
}

void excluir_tarefas(void) { // Esta tela antece a tela que exibirá os dados das tarefas -> a mesma que exibe os dados da tarefa
    limpar_tela();
    char cpf[17];
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");

    printf("Informe seu CPF: ");
    read_cpf();

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
