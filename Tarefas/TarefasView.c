#include <stdio.h>

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

    char title[MAX_NAME_LENGTH];
    printf("Informe o titulo dessa tarefa: ");
    read_string(title);

    char description[MAX_DESCRIPTION_LENGTH];
    printf("Informe a descrição dessa tarefa: ");
    read_description(description);

    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    char year[MAX_YEAR_LENGHT];
    printf("Informe a data para realizar essa tarefa (xx/xx/xxxx): ");
    read_date(day, month, year);

    char turn = ' ';
    printf("Informe o turno de realização dessa tarefa: ");
    printf("\n[1] Manha\n[2] Tarde\n[3] Noite\n");
    read_generic_123(&turn);

    char priority = ' ';
    printf("Informe a prioridade dessa tarefa: ");
    printf("\n[1] Alta\n[2] Media\n[3] Baixa\n");
    read_generic_123(&priority);

    char status = ' ';
    printf("Informe o status dessa tarefa: ");
    printf("\n[1] Pendente\n[2] Concluída\n[3] Cancelada\n");
    read_generic_123(&status);

    show_sucess("Tarefa cadastrada com sucesso! <ENTER> para continuar\n");
    limpa_buffer();
}

void exibir_tarefas(void) { // Esta tela antecede a tela que exibirá os dados das tarefas
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Exibir tarefas                |\n");
    printf("--------------------------------------------------\n");

    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    dados_tarefas();
}

void editar_tarefas(void) { // Esta tela antecede a tela -> alterar dados
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Editar Tarefas                |\n");
    printf("--------------------------------------------------\n");

    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    alterar_dados_tarefas();
}

void excluir_tarefas(void) { // Esta tela antece a tela que exibirá os dados das tarefas -> a mesma que exibe os dados da tarefa
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                  Excluir Tarefas               |\n");
    printf("--------------------------------------------------\n");

    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    dados_tarefas();
}

void dados_tarefas(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados da Tarefa                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   CPF   |          Título          |                   Descrição                   |    Data   |    Turno   |     Prioridade    |    Status    |\n");
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
    printf("|   CPF   |    1   ->   Título       |             2   ->   Descrição                | 3 -> Data | 4 -> Turno |  5 -> Prioridade  | 6 -> Status  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}
