#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

#include "UsuariosModel.h"


int insert_to_user(User *users, const char* file_name){

    create_path("data/");

    FILE *fp = fopen(file_name, "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:%-229s;%s#1\n", users->cpf, users->name, users->phone);
    fclose(fp);
    return TRUE;
}

// int udpate_user(User *users, const char* file_name){
//     const char *file_temp = "/data/temp.txt";

//     FILE *fp = fopen(file_name, "r");
//     if (fp == NULL) return FALSE;

//     FILE *fp_temp = fopen(file_temp, "w");
//     if (fp_temp == NULL) return FALSE;

//     char line[MAX_LINE_LENGTH];
//     while(fgets(line, sizeof(line), fp)){
//         if (strstr(line, users->cpf) == NULL){
//             fprintf(fp_temp, "%s", line);
//         }
//         else{
//             fprintf(fp_temp, "%s:%-229s;%s", users->cpf, users->name, users->phone);
//         }
//     }

//     fclose(fp);
//     fclose(fp_temp);

//     remove(file_name);
//     rename(file_temp, file_name);

//     return TRUE;

// }

int update_name_in_users(User *users, const char* file_name){
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_SIZE];
    long pos; // Cursor
    int found = FALSE;

    while (fgets(line, LINE_SIZE, fp) != NULL){
        if (strstr(line, users->cpf) != NULL){
            pos = ftell(fp) - strlen(line);

            char *delimiter_pos = strchr(line, ':');
            if (delimiter_pos != NULL){
                long name_pos = pos + (delimiter_pos - line) + 1;

                // Posiciona cursor
                fseek(fp, name_pos, SEEK_SET);
                fprintf(fp, "%-229s", users->name);
                fflush(fp);
                found = TRUE;
            }

            break;

        }
    }
    return found;
}

int update_phone_in_users(User *users, const char *file_name){
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_SIZE];
    long pos; // Cursor
    int found = FALSE;

    while (fgets(line, LINE_SIZE, fp) != NULL){
        if (strstr(line, users->cpf) != NULL){
            pos = ftell(fp) - strlen(line);

            char *delimiter_pos = strchr(line, '#');
            if (delimiter_pos != NULL){
                long phone_pos = pos + (delimiter_pos - line) + 1;

                // Posiciona cursor
                fseek(fp, phone_pos, SEEK_SET);
                fprintf(fp, "%s", users->phone);
                fflush(fp);
                found = TRUE;
            }

            break;            
        }
    }
    return found;
}

int update_status_in_users(User *users, const char *file_name, const char *dir){
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_SIZE];
    long pos;
    int found = FALSE;

    while (fgets(line, LINE_SIZE, fp) != NULL){
        if (strstr(line, users->cpf) != NULL){
            pos = ftell(fp) - strlen(line);

            char *delimiter_pos = strchr(line, '#');

            long status_pos = pos + (delimiter_pos - line) + 1;

            char status_actual = *(delimiter_pos + 1);

            if(strcmp(dir, "0") == 0 && status_actual == '0'){
                fclose(fp);
                return FALSE;
            } else if (strcmp(dir, "1") == 0 && status_actual == '1'){
                fclose(fp); 
                return FALSE;
            }

            char new_status = (status_actual == '1') ? '0' : '1';

            fseek(fp, status_pos, SEEK_SET);
            fprintf(fp, "%c", new_status);
            fflush(fp);
            found = TRUE;
            break;
        }
    }
    fclose(fp);
    return found;
}

int select_all_user(const char *file_name){
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL) return FALSE;

    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), fp)){
        char *cpf = strtok(line, ":");
        char *name = strtok(NULL, ";");
        char *phone = strtok(NULL, "#");
        char *status = strtok(NULL, "\n");

        if (name != NULL) {
            while(isspace((unsigned char)*name)) name++;
            char *end = name + strlen(name) - 1;
            while(end > name && isspace((unsigned char)*end)) end--;
            *(end + 1) = '\0';
        }

        if(cpf && name && phone && *status == '1') {
            printf("| CPF: %s:\tNOME: %s\tTELEFONE: %s\n", cpf, name, phone);
            printf("|------------------------------------------------+-----+------------------------------------------------|\n");
        }
    }

    fclose(fp);
    return TRUE;
}

int load_user(const char* cpf, User **users){
    FILE *fp = fopen("data/users.txt", "r");
    if(fp == NULL) return FALSE;

    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), fp)){

        // Verifica se a linha começa com o CPF
        if(strncmp(line, cpf, strlen(cpf)) == 0){

            // Tokeniza a linha
            char *user_cpf = strtok(line, ":");
            char *name = strtok(NULL, ";");
            char *phone = strtok(NULL, "#");
            char *status = strtok(NULL, "\n");

            if(strcmp(status, "0") == 0){
                fclose(fp);
                return FALSE;
            }

            // Remove espaços extras no nome
            if (name != NULL) {
                while(isspace((unsigned char)*name)) name++;
                char *end = name + strlen(name) - 1;
                while(end > name && isspace((unsigned char)*end)) end--;
                *(end + 1) = '\0';
            }

            // Verifica se todas as variáveis são válidas
            if(user_cpf && name && phone) {
                // Verifica se o CPF corresponde
                if(strcmp(user_cpf, cpf) == 0){
                    // Se encontrar o usuário, aloca as strings
                    (*users)->cpf = strdup(user_cpf);
                    (*users)->name = strdup(name);
                    (*users)->phone = strdup(phone);
                    fclose(fp);
                    return TRUE;
                }
            }
        }

    }

    fclose(fp);
    return FALSE;
}
