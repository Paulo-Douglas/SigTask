#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

#include "UsuariosModel.h"


/**
 * @brief Insere um novo usuário no arquivo.abort
 * 
 * @param users Estrutura contendo os dados do usuário.
 * @param file_name Caminho para o arquivo onde os dados do usuário serão inseridos.
 * 
 * @return TRUE se o usuário foi inserido com sucesso, FALSE caso contrário.
 */
int insert_user_to_file(User *users, const char* file_name){

    create_path("data/");

    FILE *fp = fopen(file_name, "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:%-229s;%s#1\n", users->cpf, users->name, users->phone);
    fclose(fp);
    return TRUE;
}

/**
 * @brief Atualiza os dados de um usuário no arquivo.
 * 
 * @param user Estrutura contendo os dados do usuário.
 * @param delimit Delimitador utilizado para identificar o campo a ser alterado.
 * @param new_data Novo dado para o campo especificado.
 * @param lenght Tamanho do novo dado.
 * 
 * @return TRUE se os dados foram atualizados com sucesso, FALSE caso contrário.
 */
int update_data_user(User *user, const char delimit, const char *new_data, const int lenght){
    FILE *fp = fopen("data/users.txt", "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_USER];
    long pos;
    int found = FALSE;

    while(fgets(line, LINE_USER, fp) != NULL){
        if (strstr(line, user->cpf) != NULL){
            pos = ftell(fp) - strlen(line);

            char *pos_data = strchr(line, delimit);
            if (pos_data != NULL){
                long name_pos = pos + (pos_data - line) + 1;

                fseek(fp, name_pos, SEEK_SET);
                fprintf(fp, "%-*s", lenght, new_data);
                fflush(fp);
                found = TRUE;
            }
            break;
        }
    }
    fclose(fp);
    return found;
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

        while (isspace((unsigned char)*name)) name++;
        char *end = name + strlen(name) - 1;
        while (end > name && isspace((unsigned char)*end)) end--;
        *(end + 1) = '\0';

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

