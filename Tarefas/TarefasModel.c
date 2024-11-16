#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "TarefasModel.h"

typedef struct
{
    char *cpf;
    char *title;
    char *description;
    char *day;
    char month;
    int year;
    char *turn;
    char *priority;
    char *status;
    char *data;  
} Tasks;

int load_task(const char *cpf){
    Tasks information;
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_LINE_LENGTH];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) && !found){

        char *cpf_line = strtok(line, ",");
        if(strcmp(cpf_line, cpf) == 0){
            char *title_line = strtok(NULL, ",");
            char *description_line = strtok(NULL, ",");
            char *data_line = strtok(NULL, ",");
            char *turn_line = strtok(NULL, ",");
            char *priority_line = strtok(NULL, ",");
            char *status_line = strtok(NULL, ",");

            information.cpf = cpf_line;
            information.title = title_line;
            information.description = description_line;
            information.data = data_line;
            information.turn = turn_line;
            information.priority = priority_line;
            information.status = status_line;

            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
            printf("| Título: %s\n", information.title);
            printf("| CPF: %s\n", information.cpf);
            printf("| Descrição: %s\n", information.description);
            printf("| Data: %s\n", information.data);
            printf("| Turno: %s\n", information.turn);
            printf("| Prioridade: %s\n", information.priority);            
            printf("| Status: %s\n", information.status);
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

            found = TRUE;
        }
    }
    fclose(fp);
    return found;

}