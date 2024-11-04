#include <stdio.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"

#include "../Usuarios/UsuariosView.h"



/*************  ✨ Codeium Command ⭐  *************/
/******  a003a083-17b6-4b8a-a6d9-f8508e158f7b  *******/char menu_compromissos(void) {
    char op;
    limpar_tela();
    printf("----------------------------------------------------\n");
    printf("|                     Compromissos                 |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Compromisso          |\n");
    printf("|               [2] Exibir Compromisso             |\n");
    printf("|               [3] Editar Compromisso             |\n");
    printf("|               [4] Excluir Compromisso            |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_compromissos(void) {
    limpar_tela();
    printf("-------------------------------------------------------------------------------------\n");
    printf("|                                  Cadastro Tarefas                                 |\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data de início |  Data de fim |  Horário  | Prioridade  |\n");
    printf("-------------------------------------------------------------------------------------\n");

    char title[MAX_NAME_LENGTH];
    printf("Informe o Título do compromisso: ");
    read_string(title);

    char description[MAX_DESCRIPTION_LENGTH];
    printf("Informe a descrição desse compromisso: ");
    read_description(description);

    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    char year_start[MAX_YEAR_LENGHT];
    printf("Informe a data de início (xx/xx/xxxx): ");
    read_date(day_start, month_start, year_start);
    
    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    char year_end[MAX_YEAR_LENGHT];
    printf("Informe a data de fim (xx/xx/xxxx): ");
    read_date(day_end, month_end, year_end);

    char time[MAX_TIME_LENGHT];
    printf("Informe o Horário do evento (xx:xx): ");
    read_time(time);

    char priority = ' ';
    printf("Informe a prioridade desse compromisso: ");
    read_generic_123(&priority);

    show_sucess("Compromisso cadastrado com sucesso! <ENTER> para continuar\n");
    limpa_buffer();
}

void exibir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Exibir Compromissos            | \n");
    printf("--------------------------------------------------\n");

    char cpf[MAX_CPF_LENGTH];
    printf("Informe o CPF: ");
    read_cpf(cpf);
    
    dados_compromissos();
}    

void editar_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Editar Compromissos            |\n");
    printf("--------------------------------------------------\n");
    
    char cpf[MAX_CPF_LENGTH];
    printf("Informe o CPF: ");
    read_cpf(cpf);
    
    alterar_dados_compromissos();
}

void excluir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                Excluir Compromissos            |\n");
    printf("--------------------------------------------------\n");
    
    char cpf[MAX_CPF_LENGTH];
    printf("Informe o CPF: ");
    read_cpf(cpf);

    dados_compromissos();
}

void dados_compromissos(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados do Compromisso                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  ID  |        Título        |                Descrição                |    Data de início  |    Data de fim  |    Horário   |    Prioridade   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void alterar_dados_compromissos(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                          Alterar Dados do Compromisso                                                         |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |  1   ->   Título     |        2   ->   Descrição           | 3 -> Data de início | 4 -> Data de fim|  5 -> Horário | 6 -> Prioridade |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}