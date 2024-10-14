#include <stdio.h>
#include "UsuariosView.h"

char nome[50];
char cpf[17];
char telefone[17];

char menu_usuarios(void) {
    char op;
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                     Usuários                   |\n");
    printf("--------------------------------------------------\n");
    printf("|                [1] Cadastre - se               |\n");
    printf("|                [2] Exibir Dados                |\n");
    printf("|                [3] Editar Dados                |\n");
    printf("|                [4] Excluir Conta               |\n");
    printf("|                [0] Sair                        |\n");
    printf("--------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_usuarios(void) {
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("|                      Cadastre - se                  |\n");
    printf("-------------------------------------------------------\n");
    printf("|      Nome      |      CPF      |      Telefone      |\n");
    printf("-------------------------------------------------------\n");
}

void exibir_dados_usuario(void) {
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("|                      Exibir Dados                   |\n");
    printf("-------------------------------------------------------\n");
}

void alterar_dados_usuario(void) {
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("|                      Alterar Dados                  |\n");
    printf("-------------------------------------------------------\n");
}

void excluir_usuario(void) {
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("|                     Excluir Usuário                 |\n");
    printf("-------------------------------------------------------\n");
}

void dados_usuario(void) { // será implementado as variveis de cada dado
    printf("\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                            Dados do Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |                         Nome                         |     CPF     |         Telefone        |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}

void alterar_dados_usuario(void) { // será implementado as variveis de cada dado
    printf("\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                       Alterar Dados do Usuário                                        |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |           1      ->     Nome                         |  2 -> CPF   |  3   ->  Telefone       |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}