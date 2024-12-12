#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"



int insert_user_to_file(User *user){
    create_path("data/");

    FILE *fp = fopen("data/users.dat", "ab");
    if (fp == NULL) return FALSE;
    int result = FALSE;

    if (fwrite(user, sizeof(User), 1, fp)) result = TRUE;

    fclose(fp);
    return result;
}


int update_data_user(const char *cpf, const char *new_value, const char *field, int length) {
    FILE *fp = fopen("data/users.txt", "r+");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    memset(line, 0, sizeof(line));
    int found_cpf = 0;
    long pos = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, cpf) != NULL) {
            found_cpf = 1;
        }

        if (found_cpf && strstr(line, field) != NULL) {
            char *field_pos = strstr(line, field);
            if (field_pos == NULL) break;

            pos = ftell(fp) - strlen(line) + (field_pos - line) + strlen(field);
            fseek(fp, pos, SEEK_SET);

            fprintf(fp, "%-*s", length, new_value);

            fclose(fp);
            return 1;
        }

        memset(line, 0, sizeof(line));
    }

    fclose(fp);
    return 0;
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
