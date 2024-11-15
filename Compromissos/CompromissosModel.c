#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "CompromissosModel.h"


int load_compromiser(const char *cpf){
    Compromisers information;

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char *line = malloc(MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_CALENDAR_LENGHT + MAX_TIME_LENGHT + MAX_PRIORITY_LENGHT + 7);  
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) && !found){

        char *cpf_line = strtok(line, ",");

        if(strcmp(cpf_line, cpf) == 0){
            char *title_line = strtok(NULL, ",");
            char *description_line = strtok(NULL, ",");
            char *data_line_start = strtok(NULL, ",");
            char *data_line_end = strtok(NULL, ",");
            char *time_line = strtok(NULL, ",");
            char *priority_line = strtok(NULL, ",");

            strcpy(information.cpf, cpf_line);
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
            strcpy(information.title, title_line);
            printf("| Título: %s\n", information.title);
            printf("| CPF: %s\n", information.cpf);
            strcpy(information.description, description_line);
            printf("| Descrição: %s\n", information.description);
            strcpy(information.data_start, data_line_start);
            printf("| Data inicial: %s\n", information.data_start);
            strcpy(information.data_end, data_line_end);
            printf("| Data final: %s\n", information.data_end);
            strcpy(information.time, time_line);
            printf("| Tempo: %s\n", information.time);
            strcpy(information.priority, priority_line);
            printf("| Prioridade: %s\n", information.priority);            
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

            found = TRUE;
        }
    }

    return found;

}
