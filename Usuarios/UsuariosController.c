#include <stdio.h>
#include <stdlib.h>

#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


int register_user(void){
    User users;

    printf("Informe o CPF: ");
    input(&users.cpf);

    printf("Informe o nome: ");
    input(&users.name);

    printf("Informe o telefone: ");
    input(&users.phone);

    int result = insert_to_user(&users, "data/users.txt");

    free(users.name);
    free(users.cpf);
    free(users.phone);

    return result;
}

int search_user(const char* cpf){
    if(cpf_unique_user(cpf, "data/users.txt")){
        return TRUE;
    } else {
        return FALSE;
    }
}

int upload_data_user(const char* cpf){

    if(load_user(cpf)){
        return TRUE;
    } else {
        return FALSE;
    }
}