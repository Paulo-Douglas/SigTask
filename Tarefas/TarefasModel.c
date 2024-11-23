#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "TarefasModel.h"

int insert_into_tasks(const char *file_name, Tasks *task) {
    FILE *fp = fopen(file_name, "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%-11s:%-50s[%-100s]%-10s;%s(%s)%s\n",
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