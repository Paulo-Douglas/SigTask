#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"



int insert_user_to_file(User *users){
    create_path("data/");

    FILE* fp = fopen("data/users.txt", "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%s:{", users->cpf);
    fprintf(fp, "%s %-50s,", FIELD_NAME, users->name);
    fprintf(fp, "%s %s,", FIELD_PHONE, users->phone);
    fprintf(fp, "%s %s", FIELD_STATUS, users->status);
    fprintf(fp, "};\n");

    fclose(fp);
    return TRUE;
}


int update_data_user(const char *cpf, const char *new_value, const char *field, int length) {
    FILE *fp = fopen("users.txt", "r+");
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
    FILE *fp = fopen("users.txt", "r");
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

            printf("CPF -> %s\n\tUsuário: %s\n\tTelefone: %s\n\tStatus: %s\n", users.cpf, users.name, users.phone, strcmp(users.status, "0") ? "Inativo" : "Ativo");

        }
    }

    fclose(fp);
    return users;
}


/**
 * @brief Atualiza o status de um usuário no arquivo.
 * 
 * @param users Estrutura contendo os dados do usuário.
 * @param file_name Caminho para o arquivo onde os dados do usuário serão atualizados.
 * @param dir Diretiva que determina a operação a ser realizada: 
 *             "0" para reativar, "1" para desativar ou "2" para alterar.
 * 
 * @return TRUE se o status foi atualizado com sucesso, FALSE caso contrário.
 */
int update_user_status(User *users, const char *file_name, const char *dir){
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_USER];
    long pos;
    int found = FALSE;

    while (fgets(line, LINE_USER, fp) != NULL){
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


/**
 * @brief Seleciona todos os usuários ativos do arquivo.
 * 
 * @param file_name Caminho para o arquivo onde os dados dos usuários ativos serão selecionados.
 * @return TRUE se os dados foram selecionados com sucesso, FALSE caso contrário.
 */
int select_all_users(const char *file_name){
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL) return FALSE;

    char line[LINE_USER];
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



/**
 * @brief Carrega os dados de um usuário do arquivo.
 * 
 * @param cpf Cpf do usuário.
 * @param users Estrutura contendo os dados do usuário.
 * @param mode EDIT // NULL
 * 
 * @return TRUE se os dados foram carregados com sucesso, FALSE caso contrário.
 */
int load_user_from_users(const char* cpf, User *users, const char* mod) {
    FILE *fp = fopen("data/users.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return FALSE;
    }

    char line[LINE_USER];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, cpf, strlen(cpf)) != 0) {
            continue;
        }

        char *user_cpf = strtok(line, ":");
        char *name = strtok(NULL, ";");
        char *phone = strtok(NULL, "#");
        char *status = strtok(NULL, "\n");

        if (!user_cpf || !name || !phone || !status) {
            continue;
        }

        delete_spaces(name);

        // Verificar se o usuário esta ativo, caso seja EDIÇÃO
        if ((strcmp(mod, "EDIT") == 0) && (*status == '0')) {
            fclose(fp);
            return FALSE;
        }

        users->cpf = strdup(user_cpf);
        users->name = strdup(name);
        users->phone = strdup(phone);

        fclose(fp);
        return TRUE;
    }

    fclose(fp);
    return FALSE;
}

