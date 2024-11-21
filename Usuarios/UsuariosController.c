#include <stdio.h>
#include <stdlib.h>

#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


int register_user(void){
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

    int result = insert_to_user(&users, "data/users.txt");

    free(users.name);
    free(users.cpf);
    free(users.phone);

    return result;
}

int upload_data_user(const char* cpf, User *users){
    return load_user(cpf, &users);
}

int update_data_user(User *users) {
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
                update = update_name_in_users(users, "data/users.txt");
                break;
            case '2':
                printf("|\tTelefone: ");
                users->phone = read_phone();
                update = update_phone_in_users(users, "data/users.txt");
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
