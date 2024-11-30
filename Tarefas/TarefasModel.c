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
int insert_into_tasks(Tasks *task) {
    create_path("data/");

    int id_len = get_next_id("data/tasks.txt") + 1;


    FILE *fp = fopen("data/tasks.txt", "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%d:{", id_len);
    fprintf(fp, "%s%s,", FIELD_CPF, task->cpf);
    fprintf(fp, "%s%-*s,", FIELD_TITLE, VARCHAR50, task->title);
    fprintf(fp, "%s%-*s,", FIELD_DESCRIPTION, VARCHAR50, task->description);
    fprintf(fp, "%s%s,", FIELD_DATA, task->data);
    fprintf(fp, "%s%s,", FIELD_TURN, task->turn);
    fprintf(fp, "%s%s,", FIELD_PRIORITY, task->priority);
    fprintf(fp, "%s%s", FIELD_STATUS, task->status);
    fprintf(fp, "}\n");
    
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

    while (fgets(line, sizeof(line), fp) != NULL){
        char *id_line = strtok(line, ":");
        if(id_line == NULL) continue;

        if(strcmp(id_line, id) == 0){
            char *field_cpf = strtok(NULL, ":");
            if(field_cpf == NULL) continue;
            char *cpf = strtok(NULL, ",");

            char *field_title = strtok(NULL, ":");
            if(field_title == NULL) continue;
            char *title = strtok(NULL, ",");

            char *field_description = strtok(NULL, ":");
            if(field_description == NULL) continue;
            char *description = strtok(NULL, ",");

            char *field_date = strtok(NULL, ":");
            if(field_date == NULL) continue;
            char *data = strtok(NULL, ",");

            char *field_turn = strtok(NULL, ":");
            if(field_turn == NULL) continue;
            char *turn = strtok(NULL, ",");

            char *field_priority = strtok(NULL, ":");
            if(field_priority == NULL) continue;
            char *priority = strtok(NULL, ",");

            char *field_status = strtok(NULL, ":");
            if(field_status == NULL) continue;
            char *status = strtok(NULL, "}");

            task->cpf = strdup(cpf);
            task->title = strdup(title);
            task->description = strdup(description);
            task->data = strdup(data);
            task->turn = strdup(turn);
            task->priority = strdup(priority);
            task->status = strdup(status);
            found = TRUE;
            break;
        }
    }

    fclose(fp);
    return found;

}
