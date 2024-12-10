#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "TarefasModel.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int insert_into_tasks(Tasks *task) {
    create_path("data/");

    int id_len = get_next_id("data/tasks.txt") + 1;


    FILE *fp = fopen("data/tasks.txt", "a");
    if (fp == NULL) return FALSE;

    fprintf(fp, "%d:{", id_len);
    fprintf(fp, "%s%s,", FIELD_CPF, task->cpf);
    fprintf(fp, "%s%-*s,", FIELD_TITLE, VARCHAR50, task->title);
    fprintf(fp, "%s%-*s,", FIELD_DESCRIPTION, VARCHAR50, task->description);
    fprintf(fp, "%s%s,", FIELD_TYPE, task->type);
    fprintf(fp, "%s%s,", FIELD_DATA, task->data);
    fprintf(fp, "%s%s,", FIELD_TURN, task->turn);
    fprintf(fp, "%s%s,", FIELD_PRIORITY, task->priority);
    fprintf(fp, "%s%s", FIELD_STATUS, task->status);
    fprintf(fp, "}\n");
    
    fclose(fp);
    return TRUE;
}


int load_task(const char *id, Tasks *task){
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[300];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) != NULL){
        char *id_team = strtok(line, ":");

        if(strcmp(id_team, id) == 0){
            char *cursor = strtok(NULL, "\n");

            char *cpf = extract_value(&cursor, ":", ",");
            char *title = extract_value(&cursor, ":", ",");
            char *description = extract_value(&cursor, ":", ",");
            char *date = extract_value(&cursor, ":", ",");
            char *turn = extract_value(&cursor, ":", ",");
            char *priority = extract_value(&cursor, ":", ",");
            char *type = extract_value(&cursor, ":", ",");
            char *status = extract_value(&cursor, ":", "}");

            task->cpf = strdup(cpf);
            task->title = strdup(title);
            task->description = strdup(description);
            task->data = strdup(date);
            task->turn = strdup(turn);
            task->type = strdup(type);
            task->priority = strdup(priority);
            task->status = strdup(status);
            found = TRUE;
            break;
        }
    }

    fclose(fp);
    return found;

}


int update_data_task(const char **id, const char *new_value, const char *field, int length) {
    FILE *fp = fopen("data/tasks.txt", "r+");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    memset(line, 0, sizeof(line));
    int found_id = 0;
    long pos = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, *id) != NULL) {
            found_id = 1;
        }

        if (found_id && strstr(line, field) != NULL) {
            char *field_pos = strstr(line, field);
            if (field_pos == NULL) break;

            pos = ftell(fp) - strlen(line) + (field_pos - line) + strlen(field);
            fseek(fp, pos, SEEK_SET);

            fprintf(fp, "%-*s", length, new_value);

            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}