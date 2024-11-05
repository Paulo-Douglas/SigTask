#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../libs/utils.h"

#include "UsuariosModel.h"

int cpf_unique_user(const char *cpf){
    FILE *fp = fopen("data/users.txt", "r");
    if(fp == NULL){
        return 0;
    }

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_TEL_LENGTH + 3];
    char cpf_user[MAX_CPF_LENGTH];

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%14[^,]", cpf_user);

        // Comparação de vetores
        if (strcmp(cpf, cpf_user) == 0) {
            fclose(fp);
            return TRUE;
        }

    }

    fclose(fp);
    return FALSE;

}

int save_user(char *name, char *cpf, char *phone){

    if(cpf_unique_user(cpf)){
        return FALSE;
    }

    struct stat path = {0};
    if(stat("data", &path) == -1){
        mkdir("data", 0700);
    }

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