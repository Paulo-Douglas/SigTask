#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "UsuariosModel.h"

int insert_to_user(User *users, const char* file_name){
    FILE *fp = fopen(file_name, "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:%-229s;%s\n", users->cpf, users->name, users->phone);
    fclose(fp);
    return TRUE;
}


int load_user(const char *cpf){
    User usuario;

    FILE *fp = fopen("data/users.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_LINE_LENGTH];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) && !found){

        char *cpf_line = strtok(line, ",");

        if(strcmp(cpf_line, cpf) == 0){
            usuario.cpf = cpf_line;

            char *name_line = strtok(NULL, ",");
            name_line[strcspn(name_line, "\n")] = 0;
            usuario.name = name_line;

            char *phone_line = strtok(NULL, ",");
            phone_line[strcspn(phone_line, "\n")] = 0;
            usuario.phone = phone_line;

            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            printf("| CPF: %s\n", usuario.cpf);
            printf("| Nome: %s\n", usuario.name);
            printf("| Telefone: %s\n", usuario.phone);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            found = TRUE;
        }
    }

    fclose(fp);

    return found;

}