#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UsuariosView.h"
#include "UsuariosController.h"
#include "UsuariosModel.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


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
    printf("|                [5] Reativar Conta              |\n");
    printf("|                [0] Sair                        |\n");
    printf("--------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    limpar_tela();
    limpa_buffer();
    return op;
}

void cadastrar_usuarios() {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                   Cadastre - se                                       |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    if(register_user()){
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_sucess("| Cadastrado com sucesso!\n");
    } else {
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_error("| [ERRO]: CPF ja cadastrado ou erro ao cadastrar!\n");
        show_error("| Se deseja reativar a conta, escolha a opcao [5] Reativar conta\n");
    }
    printf("| Tecle <ENTER> para continuar...");
    getchar();
    limpa_buffer();
}

void exibir_dados_usuario(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                               Exibir Dados                                            |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    select_all_user("data/users.txt");
    printf("| Tecle <ENTER> para continuar...");
    limpa_buffer();
}

void alterar_dados_usuario(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                               Alterar Dados                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};

    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "2";

    if(!upload_data_user(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        dados_usuario(&users);
        result = update_data_user(&users);   
    }

    if (result){
        show_sucess("| Dados alterados com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao alterar!\n");
    }
    printf("| Tecle <ENTER> para continuar...");
    getchar();
    limpa_buffer();
}

void excluir_usuario(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                             Excluir Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "1";


    if(!upload_data_user(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        dados_usuario(&users);
        result = update_status_in_users(&users, "data/users.txt", "0");
    }

    if(result){
        show_sucess("| Conta excluida com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao excluir!\n");
    }
    printf("| Tecle <ENTER> para continuar...");
    getchar();
    limpa_buffer();
}

void reativar_usuario(void){
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                             Reativar Usuário                                          |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "0";

    if(!upload_data_user(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        dados_usuario(&users);
        result = update_status_in_users(&users, "data/users.txt", "1");
    }

    if(result){
        show_sucess("| Conta reativada com sucesso!\n");
    } else {
        show_error("| [ERRO]: Erro ao reativar!\n");
    }

    printf("| Tecle <ENTER> para continuar...");
    getchar();
    limpa_buffer();
}

void dados_usuario(User *users) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                            Dados do Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|CPF: %s\n", users->cpf);
    printf("|Nome: %s\n", users->name);
    printf("|Telefone: %s\n", users->phone);
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}