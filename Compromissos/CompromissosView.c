#include <stdio.h>
#include "TarefasView.h"

void menu_compromissos(void) {
    printf("\n");
    printf("---------------------------------------------------\n");
    printf("|                    Compromissos                  |\n");
    printf("---------------------------------------------------\n");
    printf("|               [1] Cadastrar Compromisso          |\n");
    printf("|               [2] Exibir Compromisso             |\n");
    printf("|               [3] Editar Compromisso             |\n");
    printf("|               [4] Excluir Compromisso            |\n");
    printf("|               [0] Sair                           |\n");
    printf("--------------------------------------------------\n");

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

void editar_compromissos(void) { // Esta tela antecede a tela -> alterar dados
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                 Editar Compromissos             |\n");
    printf("--------------------------------------------------\n");
}