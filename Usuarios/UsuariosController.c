#include <stdio.h>
#include <stdlib.h>

#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


/**
 * @brief Cadastra um novo usuario.
 * 
 * Recebe do usuario o CPF, nome e telefone e cadastra um novo usuario.
 * 
 * @return TRUE se o usuario for cadastrado com sucesso, FALSE caso contrario.
 */
int insert_user(void){
    User users = {NULL, NULL, NULL};

    printf("|\tCPF: ");
    users.cpf = read_cpf();

    if(cpf_unique_user(users.cpf, "data/users.txt")){
        return FALSE;
    }

    printf("|\tNome: ");
    users.name = read_string();

    printf("|\tTelefone: ");
    users.phone = read_phone();

    int result = insert_user_to_file(&users, "data/users.txt");

    free(users.name);
    free(users.cpf);
    free(users.phone);

    return result;
}


/**
 * @brief Faz o upload dos dados de um usuário.
 * 
 * Esta função carrega os dados de um usuário a partir de um arquivo,
 * utilizando o CPF fornecido para a busca. Dependendo da diretiva fornecida,
 * pode alterar, excluir ou reativar os dados do usuário.
 *
 * @param cpf CPF do usuário cujos dados serão carregados.
 * @param users Ponteiro para a estrutura User onde os dados do usuário serão armazenados.
 * @param dir Diretiva que determina a operação a ser realizada: "0" para reativar, 
 *            "1" para excluir ou "2" para alterar.
 * 
 * @return TRUE se os dados foram carregados com sucesso, FALSE caso contrário.
 */
int upload_user_data(const char* cpf, User *users, const char **dir) {
    return load_user_from_users(cpf, &users, dir);
}


/**
 * @brief Altera os dados de um usuário.
 *
 * Esta função permite alterar o nome ou telefone de um usuário. Ela
 * apresenta um menu para o usuário escolher qual dado deseja alterar e
 * solicita entrada para o novo valor. Em seguida, a função atualiza o
 * arquivo de usuários com o novo valor.
 *
 * @param users Ponteiro para a estrutura User que contém os dados do
 *              usuário a serem alterados.
 *
 * @return TRUE se os dados forem alterados com sucesso, FALSE caso
 *         contrário.
 */
int update_user_data(User *users) {
    char opc = '\0';
    int update = FALSE;

    do {
        printf("| Escolha uma opção para alterar: (1) Nome, (2) Telefone, (0) Sair: \n");
        opc = getchar();
        getchar();
        switch (opc) {
            case '1':
                printf("|\tNome: ");
                users->name = read_string();
                update = update_user_name(users, "data/users.txt");
                break;
            case '2':
                printf("|\tTelefone: ");
                users->phone = read_phone();
                update = update_user_phone(users, "data/users.txt");
                break;
            case '0':
                update = TRUE;
                break;
            default:
                printf("| Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opc != '0');

    return update;
}
