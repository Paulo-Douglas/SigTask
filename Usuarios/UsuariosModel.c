#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "UsuariosModel.h"


int load_user(const char *cpf){
    User usuario;

    FILE *fp = fopen("data/users.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_TEL_LENGTH + 3];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) && !found){

        char *cpf_line = strtok(line, ",");

        if(strcmp(cpf_line, cpf) == 0){
            char *name_line = strtok(NULL, ",");
            name_line[strcspn(name_line, "\n")] = 0;

            char *phone_line = strtok(NULL, ",");
            phone_line[strcspn(phone_line, "\n")] = 0;

            strcpy(usuario.cpf, cpf_line);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            printf("| CPF: %s\n", usuario.cpf);

            strcpy(usuario.name, name_line);
            printf("| Nome: %s\n", usuario.name);

            strcpy(usuario.phone, phone_line);
            printf("| Telefone: %s\n", usuario.phone);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            found = TRUE;
        }
    }

    return TRUE ? found : FALSE;

}