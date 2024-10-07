#include <stdio.h>
#include "UsuariosView.h"

void menu_usuarios(void) {
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