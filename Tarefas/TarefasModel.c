#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "TarefasModel.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"



/**
 * @brief Função para inserir uma nova tarefa no arquivo de tarefas
 * 
 * @param file_name Nome do arquivo de tarefas.
 * @param task Tarefa a ser inserida.
 * 
 * @return TRUE se a tarefa foi inserida com sucesso, FALSE caso contrário.
 */
int insert_into_tasks(const char *file_name, Tasks *task) {
    create_path("data/");

    int id_len = get_next_id("data/tasks.txt");


    FILE *fp = fopen(file_name, "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%d,%-14s:%-50s[%-100s]%-10s;%s(%s)%s\n",
            id_len,
            task->cpf,
            task->title,
            task->description,
            task->data,
            task->turn,
            task->priority,
            task->status);
    
    fclose(fp);
    return TRUE;
}


/**
 * @brief Função para carregar tarefa do arquivo de tarefas associadas ao cpf.
 * 
 * @param cpf CPF do usuário.
 * @param task Tarefa a ser carregada.
 * 
 * @return TRUE se a tarefa foi carregada com sucesso, FALSE caso contrário.
 */
int load_task(const char *id, Tasks *task){
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[300];
    int found = FALSE;
    int line_number = 0;

    while (fgets(line, sizeof(line), fp) != NULL){
        char *id_line = strtok(line, ",");
        if(id_line == NULL) continue;

        if(strcmp(id_line, id) == 0){
            char *cpf_line = strtok(NULL, ":");
            char *title_line = strtok(NULL, "[");
            char *description_line = strtok(NULL, "]");
            char *data_line = strtok(NULL, ";");
            char *turn_line = strtok(NULL, "(");
            char *priority_line = strtok(NULL, ")");
            char *status_line = strtok(NULL, "\n");


            if (strcmp(priority_line, "B") == 0){
                task->priority = strdup("Baixa");
            } else if (strcmp(priority_line, "M") == 0){
                task->priority = strdup("Media");
            } else {
                task->priority = strdup("Alta");
            }

            if(strcmp(turn_line, "M") == 0){
                task->turn = strdup("Manha");
            } else if(strcmp(turn_line, "T") == 0){
                task->turn = strdup("Tarde");
            } else {
                task->turn = strdup("Noite");
            }

            if (strcmp(status_line, "1") == 0){
                task->status =  strdup("Aberta");
            } else {
                task->status = strdup("Fechada");
            }

            task->cpf = strdup(cpf_line);
            task->title = strdup(title_line);
            task->description = strdup(description_line);
            task->data = strdup(data_line);

            display_data_task(task, line_number, id_line);

            line_number++;
            found = TRUE;
            getchar();
        }
    }
    fclose(fp);
    return found;

}


/**
 * @brief Função para atualizar a data de uma tarefa
 * 
 * @param task Estrutura contendo os dados da tarefa.
 * 
 * @param delimit Delimitador da data.
 * 
 * @param new_data Nova data.
 * 
 * @param lenght Tamanho da nova data.
 * 
 * @return TRUE se a data foi atualizada com sucesso, FALSE caso contrário.
 */
int update_data_task(Tasks *task, const char delimit, const char *new_data, const int lenght){
    FILE *fp = fopen("data/tasks.txt", "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_TASKS];
    long pos;
    int found = FALSE;

    while (fgets(line, LINE_TASKS, fp) != NULL){
        if(strstr(line, task->cpf) != NULL){
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
 * @brief Função para atualizar status da tarefa.
 * 
 * @param task Ponteiro que aponta para a estrutura task.
 * @param dir Diretriva para a operação.
 * 
 * @return TRUE se o status tiver sido alterado. FALSE caso contrário.
 */
int update_status_task(Tasks *task, const char *dir){
    FILE *fp = fopen("data/tasks.txt", "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_TASKS];
    long pos;
    int found = FALSE;

    while (fgets(line, LINE_TASKS, fp) != NULL){
        if(strstr(line, task->cpf) != NULL){
            pos = ftell(fp) - strlen(line);

            char *pos_status = strchr(line, ')');
            if (pos_status != NULL){
                long name_pos = pos + (pos_status - line) + 1;

                char *line_file= strtok(line, ")");
                if (line_file != NULL){
                    char *status_line = strtok(NULL, "\n");
                    if(((strcmp(status_line, "1") == 0) && (strcmp(dir, "open") == 0)) ||
                        ((strcmp(status_line, "0") == 0) && (strcmp(dir, "close") == 0))) return FALSE;
                }

                fseek(fp, name_pos, SEEK_SET);
                fprintf(fp, "%s", task->status);
                found = TRUE;
            }
            break;
        }
    } 

    fclose(fp);
    return found;
}