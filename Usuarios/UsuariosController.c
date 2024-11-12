#include <stdio.h>
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


int register_user(void){
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char phone[MAX_TEL_LENGTH];
    const char *data[4];

    printf("Informe o nome: ");
    read_string(name);
    data[0] = name;

    printf("Informe o CPF: ");
    read_cpf(cpf);
    data[1] = cpf;

    printf("Informe o telefone: ");
    read_phone(phone);
    data[2] = phone;
    data[3] = NULL;


    if(save_file(data, "data/users.txt")){
        return TRUE;
    } else {
        return FALSE;
    }

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