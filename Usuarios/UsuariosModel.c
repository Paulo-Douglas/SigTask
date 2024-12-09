#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"



int insert_user_to_file(User *users){
    create_path("data/");

    FILE* fp = fopen("data/users.txt", "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%s:{", users->cpf);
    fprintf(fp, "%s%-50s,", FIELD_NAME, users->name);
    fprintf(fp, "%s%s,", FIELD_PHONE, users->phone);
    fprintf(fp, "%s%s", FIELD_STATUS, users->status);
    fprintf(fp, "};\n");

    fclose(fp);
    return TRUE;
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


User load_user(const char *cpf){
    User users;

    FILE *fp = fopen("data/users.txt", "r");
    if (fp == NULL) exit(1);

    char line[512];

    while (fgets(line, sizeof(line), fp) != NULL) {

        if (strcmp("NULL", cpf) == 0 || strstr(line, cpf) != NULL) {

            char *cpf_pos = strtok(line, ":");
            char *name_pos = strtok(NULL, ":");
            if (name_pos == NULL) continue;
            char *name_value = strtok(NULL, ",");
            char *phone_pos = strtok(NULL, ":");
            if (phone_pos == NULL) continue;
            char *phone_value = strtok(NULL, ",");
            char *status_pos = strtok(NULL, ":");
            if (status_pos == NULL) continue;
            char *status_value = strtok(NULL, "}");

            users.cpf = strdup(cpf_pos);
            users.name = strdup(name_value);
            users.phone = strdup(phone_value);
            users.status = strdup(status_value);
            user_data(&users);
        }
    }

    fclose(fp);
    return users;
}
