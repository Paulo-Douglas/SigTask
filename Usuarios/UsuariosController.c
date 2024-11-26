#include <stdio.h>
#include <stdlib.h>

#include "UsuariosController.h"
#include "UsuariosModel.h"
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"



/**
 * @brief Cadastra um novo usuario.
 * 
 * Recebe do usuario o CPF, nome e telefone e cadastra um novo usuario.
 * 
 * @return TRUE se o usuario for cadastrado com sucesso, FALSE caso contrario.
 */
int insert_user(void){
    User users = {NULL, NULL, NULL};

    read_and_assign(&users.cpf, "|\tCPF: ", read_cpf);

    if(cpf_unique_user(users.cpf, "data/users.txt")){
        return FALSE;
    }

    read_and_assign(&users.name, "|\tNome: ", read_string);
    read_and_assign(&users.phone, "|\tTelefone: ", read_phone);

    users.status = "1";

    int result = insert_user_to_file(&users);

    free(users.name);
    free(users.cpf);
    free(users.phone);

    return result;
}


/**
 * @brief Altera os dados de um usuario.
 * 
 * @param users Estrutura contendo os dados do usuario.
 * @return TRUE se os dados forem alterados com sucesso, FALSE caso contrário.
 */
int update_user(User *users) {
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
                update = update_data_user(users, ':', users->name, 229);
                update ? show_sucess("Nome alterado com sucesso!") : show_error("Erro ao alterar nome!");
                break;
            case '2':
                printf("|\tTelefone: ");
                users->phone = read_phone();
                update = update_data_user(users, ';', users->phone, 13);
                update ? show_sucess("Telefone alterado com sucesso!") : show_error("Erro ao alterar telefone!");
                break;
            case '0':
                update = TRUE;
                break;
            default:
                show_error("| Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opc != '0');

    return update;
}
