#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UsuariosView.h"
#include "UsuariosController.h"
#include "UsuariosModel.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


/**
 * Exibe o menu de usuários com opções para cadastrar, exibir dados,
 * editar dados, excluir conta, reativar conta ou sair.
 * 
 * @return O caractere que representa a opção de menu escolhida.
 */
char user_menu(void) {
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


/**
 * Exibe a tela de cadastro de usuários.
 * 
 * Se o cadastro for efetuado com sucesso, exibe mensagem de sucesso.
 * Caso contrário, exibe mensagem de erro e informa que o CPF ja esta cadastrado ou
 * que houve um erro ao cadastrar.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 */
void register_user() {
    show_header("Cadastrar Usuário");

    if(insert_user()){
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_sucess("| Cadastrado com sucesso!\n");
    } else {
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_error("| [ERRO]: CPF ja cadastrado ou erro ao cadastrar!\n");
        show_error("| Se deseja reativar a conta, escolha a opcao [5] Reativar conta\n");
    }
    enter();
}


/**
 * Exibe a tela de exibir dados dos usuários.
 * 
 * Esta tela apenas exibe os dados dos usuários sem realizar nenhuma ação.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 */
void display_user_data(void) {
    show_header("Exibir Dados");
    User users = load_user("111.111.111-11");
    if(users.cpf == NULL) {
        show_error("| Nenhum usuário cadastrado!\n");
    }
    enter();
}


/**
 * Exibe a tela de alterar dados dos usuários.
 * 
 * Esta tela pede o CPF do usuário e, se encontrado, permite alterar os dados do usuário.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 * 
 **/
void modify_user_data(void) {
    show_header("Editar Dados");
    printf("|\tCPF:\t");
    const char *cpf = read_cpf();
    User users = load_user(cpf);

    if (users.cpf != NULL) {
        user_data(&users);
        int result = update_user(&users);   
        if (result) {
            show_sucess("| Dados alterados com sucesso!\n");
        } else {
            show_error("| [ERRO]: Erro ao alterar!\n");
        }
    }

    enter();
}


void delete_user(void) {
    show_header("Excluir Conta");
    printf("|\tCPF:\t");
    const char *cpf = read_cpf();
    User users = load_user(cpf);
    if ((users.cpf != NULL) && (strcmp(users.status, "0") != 0)) {
        update_data_user(cpf, "0", FIELD_STATUS, 1);
        show_sucess("| Conta excluida com sucesso!\n");
    }else {
        show_error("| [ERRO]: Erro ao excluir!\n");
    }
    enter();
}


void reactivate_user(void) {
    show_header("Reativar Conta");
    printf("|\tCPF:\t");
    const char *cpf = read_cpf();
    User users = load_user(cpf);
    if ((users.cpf != NULL) && (strcmp(users.status, "1") != 0)) {
        update_data_user(cpf, "1", FIELD_STATUS, 1);
        show_sucess("| Conta ativada com sucesso!\n");
    }else {
        show_error("| [ERRO]: Erro ao ativar!\n");
    }
    enter();
}


void user_data(const User *users) {
    show_header("Dados do usuário");
    printf("\033[1m|CPF:\033[m %s\n", users->cpf);
    printf("\033[1m|Nome:\033[m %s\n", users->name);
    printf("\033[1m|Telefone:\033[m %s\n", users->phone);
    printf("\033[1m|Status:\033[m %s\n", strcmp(users->status, "0") ? "Ativo" : "Invativo");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}
