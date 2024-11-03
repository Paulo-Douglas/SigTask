#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/reads.h"

#include "UsuariosController.h"

void save_user(char *name, char *cpf, char *phone){

    struct stat path = {0};
    if(stat("data", &path) == -1){
        mkdir("data", 0700);
    }

    User usario;
    FILE *fp;
    fp = fopen("data/users.txt", "a");
    fprintf(fp, "%s,%s,%s\n", usario.name, usario.cpf, usario.phone);
    fclose(fp);
}