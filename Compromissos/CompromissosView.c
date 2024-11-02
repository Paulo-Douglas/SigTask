#include <stdio.h>
#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../Usuarios/UsuariosView.h"
#include "CompromissosController.h"
#include "CompromissosView.h"

char titulo[25];
char descricao[45];
char data_inicio[11];
char data_fim[11];
char horario[6];
char prioridade[15];

char menu_compromissos(void) {
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
    printf("Informe o Título do compromisso: ");
    read_title();
    printf("Informe a descrição desse compromisso: ");
    read_description();
    printf("Informe a data de início (xx/xx/xxxx): ");
    read_date();
    printf("Informe a data de fim (xx/xx/xxxx): ");
    read_date();
    printf("Informe o Horário do evento (xx:xx): ");
    read_time();
    printf("Informe a prioridade desse compromisso: ");
    read_priority();
}

void exibir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Exibir Compromissos            | \n");
    printf("--------------------------------------------------\n");
    printf("Informe o CPF: ");
    read_cpf();
    dados_compromissos();
}    

void editar_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Editar Compromissos            |\n");
    printf("--------------------------------------------------\n");
    printf("Informe o CPF: ");
    read_cpf();
    alterar_dados_compromissos();
}

void excluir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                Excluir Compromissos            |\n");
    printf("--------------------------------------------------\n");
    printf("Informe o CPF: ");
    read_cpf();
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