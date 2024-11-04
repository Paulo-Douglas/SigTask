#include <stdio.h>
#include "../libs/reads.h"
#include "../libs/utils.h"

#include "UsuariosController.h"
#include "UsuariosModel.h"


void registro_de_usuario(void){
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char phone[MAX_TEL_LENGTH];

    printf("Informe o nome: ");
    read_string(name);

    printf("Informe o CPF: ");
    read_cpf(cpf);

    printf("Informe o telefone: ");
    read_phone(phone);

    save_user(name, cpf, phone);

}