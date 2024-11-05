#include <stdio.h>
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


int registro_de_usuario(void){
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char phone[MAX_TEL_LENGTH];

    printf("Informe o nome: ");
    read_string(name);

    printf("Informe o CPF: ");
    read_cpf(cpf);

    printf("Informe o telefone: ");
    read_phone(phone);

    if(save_user(name, cpf, phone)){
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