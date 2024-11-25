#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UsuariosView.h"
#include "UsuariosController.h"
#include "UsuariosModel.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"


User get_user_by_cpf(const char* mod) {
    User users = {NULL, NULL, NULL};
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    if (!load_user_from_users(cpf, &users, mod)) {
        show_error("| Erro ao carregar os dados do usuário!\n");
    }
    return users;
}


void process_action(const char *dir, const char *sucess, const char *error) {
    User users = get_user_by_cpf("NULL");

    if (users.cpf != NULL) {
        user_data(&users);
        int result = update_user_status(&users, "data/users.txt", dir); 
        if (result) {
            show_sucess(sucess);
        } else {
            show_error(error);
        }
    }
}


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
    select_all_users("data/users.txt");
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
    const char *mod = "EDIT";

    User users = get_user_by_cpf(mod);

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


/**
 * Exibe a tela de excluir usuários.
 * 
 * Esta tela pede o CPF do usuário e, se encontrado, exclui a conta do usuário.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 * 
 */
void delete_user(void) {
    show_header("Excluir Conta");
    process_action("0", "| Conta excluida com sucesso!", "| [ERRO]: Erro ao excluir!");
    enter();
}


/**
 * Exibe a tela de reativar usuários.
 * 
 * Esta tela pede o CPF do usuário e, se encontrado, reativa a conta do usuário.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 * 
 */
void reactivate_user(void) {
    show_header("Reativar Conta");
    process_action("1", "| Conta reativada com sucesso!", "| [ERRO]: Erro ao reativar!");
    enter();
}


void user_data(const User *users) {
    show_header("Dados do usuário");
    printf("|CPF: %s\n", users->cpf);
    printf("|Nome: %s\n", users->name);
    printf("|Telefone: %s\n", users->phone);
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}
