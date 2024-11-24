#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

#include "UsuariosModel.h"


/**
 * Insere as informações de um usuário no arquivo especificado.
 *
 * Esta função adiciona os dados de um novo usuário, incluindo CPF, nome e número de telefone,
 * ao arquivo fornecido. O arquivo é aberto no modo de adição, e uma nova linha contendo
 * os detalhes do usuário é escrita em um formato específico. A função garante que
 * o diretório de dados seja criado antes de tentar abrir o arquivo.
 *
 * @param users Ponteiro para uma struct User contendo o CPF, nome e número de telefone do usuário.
 * @param file_name O nome do arquivo onde as informações do usuário serão armazenadas.
 * @return TRUE se as informações do usuário foram escritas com sucesso no arquivo, FALSE caso contrário.
 */
int insert_user_to_file(User *users, const char* file_name){

    create_path("data/");

    FILE *fp = fopen(file_name, "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:%-229s;%s#1\n", users->cpf, users->name, users->phone);
    fclose(fp);
    return TRUE;
}

// FUNÇÃO ANTIGA DE ATUALIZAR USUÁRIO
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



/**
 * @brief Atualiza o nome de um usuário no arquivo.
 *
 * @param users estrutura com os dados do usuário.
 * @param file_name caminho para o arquivo com os dados dos usuários.
 *
 * @return FALSE se a atualização falhar, TRUE se for bem sucedida.
 */
int update_user_name(User *users, const char* file_name){
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_USER];
    long pos; // Cursor
    int found = FALSE;

    while (fgets(line, LINE_USER, fp) != NULL){
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
 * @brief Atualiza o telefone de um usuário no arquivo.
 *
 * @param users estrutura com os dados do usuário.
 * @param file_name caminho para o arquivo com os dados dos usuários.
 *
 * @return FALSE se a atualização falhar, TRUE se for bem sucedida.
 */
int update_user_phone(User *users, const char *file_name) {
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_USER];
    long pos; // Cursor
    int found = FALSE;

    while (fgets(line, LINE_USER, fp) != NULL) {
        pos = ftell(fp) - strlen(line);

        if (strstr(line, users->cpf) != NULL) {
            char *delimiter_pos = strchr(line, '#');
            if (delimiter_pos != NULL) {
                long phone_pos = pos + strchr(line, ';') - line + 1;

                fseek(fp, phone_pos, SEEK_SET);
                fprintf(fp, "%-12s", users->phone);
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
 * Esta função altera o status de um usuário identificado pelo CPF no arquivo
 * especificado. O status é alternado entre ativo ('1') e inativo ('0') com base 
 * na diretiva fornecida. Se a diretiva for "0", a função tentará reativar o usuário
 * se ele estiver inativo. Se for "1", a função tentará desativar o usuário se ele
 * estiver ativo. A função retorna FALSE se a operação não for necessária ou se o 
 * arquivo não puder ser aberto.
 *
 * @param users Estrutura contendo os dados do usuário.
 * @param file_name Caminho para o arquivo com os dados dos usuários.
 * @param dir Diretiva para a operação: "0" para reativar, "1" para desativar.
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
 * @brief Exibe todos os usuários registrados.
 *
 * Abre o arquivo especificado e exibe todos os usuários registrados nele.
 * O formato de impressão é o seguinte:
 * | CPF: <CPF>:\tNOME: <NOME>\tTELEFONE: <TELEFONE>
 * |------------------------------------------------+-----+------------------------------------------------|
 *
 * @param file_name caminho para o arquivo com os dados dos usuários.
 *
 * @return FALSE se não houver arquivo com o caminho especificado, TRUE caso contrário.
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
 * Esta função lê  o arquivo de usuários e busca um usuário com o CPF especificado.
 * Se o usuário for encontrado, a função retorna TRUE e aloca as strings para o
 * ponteiro Users passado como par metro. Caso contrário, a função retorna FALSE.
 *
 * @param cpf CPF do usuário a ser carregado.
 * @param users Ponteiro para a estrutura Users que irá armazenar os dados do usuário.
 * @param dir Diretiva para a opera o: "0" para reativar, "1" para desativar ou "2" para alterar.
 *
 * @return TRUE se o usuário foi encontrado e os dados foram carregados com sucesso, FALSE caso contrário.
 */
int load_user_from_users(const char* cpf, User **users, const char **dir){
    FILE *fp = fopen("data/users.txt", "r");
    if(fp == NULL) return FALSE;

    char line[LINE_USER];
    while(fgets(line, sizeof(line), fp)){

        // Verifica se a linha começa com o CPF
        if(strncmp(line, cpf, strlen(cpf)) == 0){

            // Tokeniza a linha
            char *user_cpf = strtok(line, ":");
            char *name = strtok(NULL, ";");
            char *phone = strtok(NULL, "#");
            const char *status = strtok(NULL, "\n");

            if(strcmp(*dir, "2") == 0 && strcmp(status, "0") == 0){ // alterar
                fclose(fp);
                return FALSE;
            } else if (strcmp(*dir, "1") == 0 && strcmp(status, "0") == 0){ // excluir
                fclose(fp);
                return FALSE;
            } else if (strcmp(*dir, "0") == 0 && strcmp(status, "1") == 0){ // reativar
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
