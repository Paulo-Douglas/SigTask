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

    printf("|\tNome: ");
    users.name = read_string();

    printf("|\tTelefone: ");
    users.phone = read_phone();
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    int result = insert_to_user(&users, "data/users.txt");

    free(users.name);
    free(users.cpf);
    free(users.phone);

    return result;
}

int search_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}

int upload_data_user(const char* cpf, User *users){
    return load_user(cpf, &users);
}