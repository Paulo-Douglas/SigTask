#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UsuariosView.h"
#include "UsuariosController.h"

#include "../libs/utils.h"
#include "../libs/reads.h"


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
    limpar_tela();
    return op;
}

void cadastrar_usuarios() {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Cadastre - se                  |\n");
    printf("-------------------------------------------------------\n");
    printf("|      Nome      |      CPF      |      Telefone      |\n");
    printf("-------------------------------------------------------\n");

    if(register_user()){
        show_sucess("Cadastrado com sucesso! <ENTER> para continuar\n");
    } else {
        show_error("[ERRO]: CPF ja cadastrado ou erro ao cadastrar \n<ENTER> para continuar\n");
    }
}

void exibir_dados_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Exibir Dados                   |\n");
    printf("-------------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_usuario();
        if(!upload_data_user(cpf)){
            show_error("Erro ao carregar os dados do usuário!\n");
        }
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 
    free(cpf);
}

void alterar_dados_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                      Alterar Dados                  |\n");
    printf("-------------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        menu_alterar_usuario();
        if(!upload_data_user(cpf)){
            show_error("Erro ao carregar os dados do usuário!\n");
        }
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 
    free(cpf);

}

void excluir_usuario(void) {
    limpar_tela();
    printf("-------------------------------------------------------\n");
    printf("|                     Excluir Usuário                 |\n");
    printf("-------------------------------------------------------\n");

    printf("Informe o CPF: ");
    char *cpf = read_cpf();

    if(!search_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_usuario();
        if(!upload_data_user(cpf)){
            show_error("Erro ao carregar os dados do usuário!\n");
        }
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 
    free(cpf);
}

void dados_usuario(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                            Dados do Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

}

void menu_alterar_usuario(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                       Alterar Dados do Usuário                                        |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |           1      ->     Nome                         |  2 -> CPF   |  3   ->  Telefone       |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}