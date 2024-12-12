#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UsuariosController.h"
#include "UsuariosModel.h"
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"


int add_user(void){
    User user = {0};

    printf("|\tCPF: ");
    char *cpf = read_cpf();
    strcpy(user.cpf, cpf);

    if(cpf_exists(user.cpf)){
        return FALSE;
    }

    printf("|\tNome: ");
    char *name = read_string();
    strcpy(user.name, name);

    printf("|\tTelefone: ");
    char *phone = read_phone();
    strcpy(user.phone, phone);

    user.status = '1';

    int result = insert_user_to_file(&user);

    return result;
}


/**
 * @brief Altera os dados de um usuario.
 * 
 * @param users Estrutura contendo os dados do usuario.
 * @return TRUE se os dados forem alterados com sucesso, FALSE caso contrário.
 */
// int update_user(User *users) {
//     char opc = '\0';
//     int update = FALSE;

//     do {
//         printf("| Escolha uma opção para alterar: (1) Nome, (2) Telefone, (0) Sair: \n");
//         opc = getchar();
//         getchar();
//         switch (opc) {
//             case '1':
//                 printf("|\tNome: ");
//                 users->name = read_string();
//                 update = update_data_user(users->cpf, users->name, FIELD_NAME, VARCHAR50);
//                 update ? show_sucess("Nome alterado com sucesso!") : show_error("Erro ao alterar nome!");
//                 break;
//             case '2':
//                 printf("|\tTelefone: ");
//                 users->phone = read_phone();
//                 update = update_data_user(users->cpf, users->phone, FIELD_PHONE, 1);
//                 update ? show_sucess("Telefone alterado com sucesso!") : show_error("Erro ao alterar telefone!");
//                 break;
//             case '0':
//                 update = TRUE;
//                 break;
//             default:
//                 show_error("| Opção inválida! Tente novamente.\n");
//                 break;
//         }
//     } while (opc != '0');

//     return update;
// }
