#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "UsuariosModel.h"


int save_user(char *name, char *cpf, char *phone){

    if(cpf_unique_user(cpf, "data/users.txt")){
        return FALSE;
    }

    create_path("data");

    User usario;

    strcpy(usario.name, name);
    strcpy(usario.cpf, cpf);
    strcpy(usario.phone, phone);

    FILE *fp;
    fp = fopen("data/users.txt", "a");
    fprintf(fp, "%s,%s,%s\n", usario.cpf, usario.name, usario.phone);
    fclose(fp);

    return TRUE;

}

int load_user(const char *cpf){
    User usuario;

    if(cpf_unique_user(cpf, "data/users.txt")) return FALSE;

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
            printf("+-------------------+-------------------------+\n");
            printf("| CPF: %s\n", usuario.cpf);

            strcpy(usuario.name, name_line);
            printf("| Nome: %s\n", usuario.name);

            strcpy(usuario.phone, phone_line);
            printf("| Telefone: %s\n", usuario.phone);
            printf("+-------------------+-------------------------+\n");

            found = TRUE;
        }
    }

    return TRUE ? found : FALSE;

}