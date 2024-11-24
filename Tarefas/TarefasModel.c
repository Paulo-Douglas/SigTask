#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "TarefasModel.h"

int insert_into_tasks(const char *file_name, Tasks *task) {
    create_path("data/");

    FILE *fp = fopen(file_name, "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%-14s:%-50s[%-100s]%-10s;%s(%s)%s\n",
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


int load_task(const char *cpf, Tasks *task){
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_LINE_LENGTH];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) && !found){

        char *cpf_line = strtok(line, ":");
        if(strcmp(cpf_line, cpf) == 0){
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

            found = TRUE;
            enter();
        }
    }
    fclose(fp);
    return found;

}


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