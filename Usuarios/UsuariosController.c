#include <stdio.h>
#include <stdlib.h>

#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


int register_user(void){
    const char *data[4];
    data[3] = NULL;

    printf("Informe o CPF: ");
    char *cpf = read_cpf();
    data[0] = cpf;

    printf("Informe o nome: ");
    char *name = read_string();
    data[1] = name;

    printf("Informe o telefone: ");
    char *phone = read_phone();
    data[2] = phone;

    int result = save_file(data, "data/users.txt");

    free(name);
    free(cpf);
    free(phone);

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