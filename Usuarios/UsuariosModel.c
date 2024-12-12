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


User load_user(const char *cpf){
    User users;

    FILE *fp = fopen("data/users.txt", "r");
    if (fp == NULL) exit(1);

//     char line[512];

//     while (fgets(line, sizeof(line), fp) != NULL) {

//         if (strstr(line, cpf) != NULL) {
//             char *cpf_user = strtok(line, ":");
//             char *cursor = strtok(NULL, "\n");

//             char *name = extract_value(&cursor, ":", ",");
//             char *phone = extract_value(&cursor, ":", ",");
//             char *status = extract_value(&cursor, ":", "}");

//             if (cpf_user && name && phone && status) {
//                 users.cpf = strdup(cpf_user);
//                 users.name = strdup(name);
//                 users.phone = strdup(phone);
//                 users.status = strdup(status);
//             }
//         }
//     }

    fclose(fp);
    return users;
}
