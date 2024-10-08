#include <stdio.h>
#include "CompromissosView.h"

void menu_compromissos(void) {
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("|                     Compromissos                 |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Compromisso          |\n");
    printf("|               [2] Exibir Compromisso             |\n");
    printf("|               [3] Editar Compromisso             |\n");
    printf("|               [4] Excluir Compromisso            |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");

}

void cadastrar_compromissos(void) {
    printf("\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("|                                  Cadastro Tarefas                                 |\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data de início |  Data de fim |  Horário  | Prioridade  |\n");
    printf("-------------------------------------------------------------------------------------\n");
}

void exibir_compromissos(void) { 
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                 Exibir Compromissos           | \n");
    printf("--------------------------------------------------\n");

}    

void editar_compromissos(void) { 
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                 Editar Compromissos             |\n");
    printf("--------------------------------------------------\n");
}

void excluir_compromissos(void) { 
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                Excluir Compromissos            |\n");
    printf("--------------------------------------------------\n");
}

void dados_compromissos(void) { // será implementado as variveis de cada dado
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados do Compromisso                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  ID  |        Título        |                Descrição                |    Data de início  |    Data de fim  |    Horário   |    Prioridade   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void alterar_dados_compromissos(void) {
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                          Alterar Dados do Compromisso                                                         |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |  1   ->   Título     |        2   ->   Descrição           | 3 -> Data de início | 4 -> Data de fim|  5 -> Horário | 6 -> Prioridade |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}