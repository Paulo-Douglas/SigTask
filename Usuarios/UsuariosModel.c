#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../libs/utils.h"
#include "../libs/validate.h"

#include "UsuariosModel.h"


int save_user(char *name, char *cpf, char *phone){

    if(cpf_unique_user(cpf, "data/users.txt")){
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