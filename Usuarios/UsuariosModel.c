#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../libs/utils.h"

#include "UsuariosModel.h"

void save_user(char *name, char *cpf, char *phone){

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
    fprintf(fp, "%s,%s,%s\n", usario.name, usario.cpf, usario.phone);
    fclose(fp);
}