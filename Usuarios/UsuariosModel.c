#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"



int insert_user(User *user){
    int id = get_next_id("data/users.dat");
    if(id == 0) id = 1;

    snprintf(user->id, sizeof(user->id), "%d", id);
    create_path("data/");

    FILE *fp = fopen("data/users.dat", "ab");
    if (fp == NULL) return FALSE;
    int result = FALSE;

    if (fwrite(user, sizeof(User), 1, fp)) result = TRUE;

    fclose(fp);
    return result;
}


int update_user(User *new_data){
    FILE *fp = fopen("data/users.dat", "rb+");
    if (fp == NULL) return FALSE;

    User user;
    while (fread(&user, sizeof(User), 1, fp)){

        if(strcmp(user.cpf, new_data->cpf) == 0){
            fseek(fp, -sizeof(User), SEEK_CUR);
            fwrite(new_data, sizeof(User), 1, fp);
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}


User* load_user(const char *cpf){
    FILE * fp = fopen("data/users.dat", "rb");
    if (fp == NULL) return NULL;

    User *user = (User *)malloc(sizeof(User));
    while (fread(user, sizeof(User), 1, fp)){
        if (strcmp(user->cpf, cpf) == 0){
            fclose(fp);
            return user;
        }
    }

    fclose(fp);
    free(user);
    return NULL;
}
