#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "TarefasModel.h"


int load_task(const char *cpf){
    Tasks information;
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_TURN_LENGHT + MAX_PRIORITY_LENGHT + MAX_STATUS_LENGHT + 7];  // tem que adicionar turn, priority, status
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

            strcpy(information.cpf, cpf_line);
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
            strcpy(information.title, title_line);
            printf("| Título: %s\n", information.title);
            printf("| CPF: %s\n", information.cpf);
            strcpy(information.description, description_line);
            printf("| Descrição: %s\n", information.description);
            strcpy(information.data, data_line);
            printf("| Data: %s\n", information.data);
            strcpy(information.turn, turn_line);
            printf("| Turno: %s\n", information.turn);
            strcpy(information.priority, priority_line);
            printf("| Prioridade: %s\n", information.priority);            
            strcpy(information.status, status_line);
            information.status[strcspn(information.status, "\n")] = 0;
            printf("| Status: %s\n", information.status);
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

            found = TRUE;
        }
    }

    return TRUE ? found : FALSE;

}