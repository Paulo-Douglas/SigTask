#include <stdio.h>
#include "UsuariosView.h"
#include "../libs/utils.h"
#include "../libs/inputs.h"


char nome[50];
char cpf[17];
char telefone[17];

char menu_usuarios(void) {
    char op;
    limpar_tela();
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

void cadastrar_usuarios(char *name, char *phone, char *cpf) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Cadastre - se                  |\n");
    printf("-------------------------------------------------------\n");
    printf("|      Nome      |      CPF      |      Telefone      |\n");
    printf("-------------------------------------------------------\n");
    
    printf("Nome: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0;
    limpa_buffer();
    printf("\n");

    printf("CPF: ");
    fgets(cpf, MAX_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    limpa_buffer();
    printf("\n");

    printf("Telefone: ");
    fgets(phone, MAX_TEL, stdin);
    phone[strcspn(phone, "\n")] = 0;
    limpa_buffer();
    printf("\n");

    printf("-------------------------------------------------------\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void show_error(const char *message) {
    printf("\033[1;31m[ERRO] %s\033[0m\n", message);
}

void show_sucess(const char *message) {
    printf("\033[1;32m[SUCESSO] %s\033[0m\n", message);
}

void exibir_dados_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Exibir Dados                   |\n");
    printf("-------------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    dados_usuario();
}

void alterar_dados_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Alterar Dados                  |\n");
    printf("-------------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    menu_alterar_usuario();
}

void excluir_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                     Excluir Usuário                 |\n");
    printf("-------------------------------------------------------\n");
    printf("Informe seu CPF: ");
    scanf("%[0-9.-]", cpf);
    dados_usuario();
}

void dados_usuario(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                            Dados do Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |                         Nome                         |     CPF     |         Telefone        |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void menu_alterar_usuario(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                       Alterar Dados do Usuário                                        |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |           1      ->     Nome                         |  2 -> CPF   |  3   ->  Telefone       |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}