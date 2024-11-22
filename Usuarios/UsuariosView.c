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
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                   Cadastre - se                                       |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    if(insert_user()){
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


/**
 * Exibe a tela de exibir dados dos usuários.
 * 
 * Esta tela apenas exibe os dados dos usuários sem realizar nenhuma ação.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 */
void display_user_data(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                               Exibir Dados                                            |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    select_all_users("data/users.txt");
    printf("| Tecle <ENTER> para continuar...");
    limpa_buffer();
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
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                               Alterar Dados                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};

    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "2"; // MOD: 2-> Alterar

    if(!upload_user_data(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        user_data(&users);
        result = update_user_data(&users);   
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


/**
 * Exibe a tela de excluir usuários.
 * 
 * Esta tela pede o CPF do usuário e, se encontrado, exclui a conta do usuário.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 * 
 */
void delete_user(void) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                             Excluir Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "1"; // MOD: 1-> Excluir


    if(!upload_user_data(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        user_data(&users);
        result = update_user_status(&users, "data/users.txt", "0");
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



/**
 * Exibe a tela de reativar usuários.
 * 
 * Esta tela pede o CPF do usuário e, se encontrado, reativa a conta do usuário.
 * 
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 * 
 */
void reactivate_user(void){
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                             Reativar Usuário                                          |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    User users = {NULL, NULL, NULL};
    printf("| Informe o CPF: ");
    char *cpf = read_cpf();
    int result = FALSE;
    const char *mod = "0"; // MOD: 0-> Reativar

    if(!upload_user_data(cpf, &users, &mod)){
        show_error("| Erro ao carregar os dados do usuário!\n");
    } else {
        user_data(&users);
        result = update_user_status(&users, "data/users.txt", "1");
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


/**
 * Exibe os dados do usuário na tela.
 * 
 * Esta função recebe um ponteiro para uma estrutura User e exibe 
 * o CPF, nome e telefone do usuário formatados em uma tabela.
 * 
 * @param users Ponteiro para a estrutura User que contém os dados 
 *              do usuário a serem exibidos.
 */
void user_data(User *users) {
    limpar_tela();
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|                                            Dados do Usuário                                           |\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|CPF: %s\n", users->cpf);
    printf("|Nome: %s\n", users->name);
    printf("|Telefone: %s\n", users->phone);
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}
