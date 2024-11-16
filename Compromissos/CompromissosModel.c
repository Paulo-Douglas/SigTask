#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "CompromissosModel.h"

typedef struct
{
    char *cpf;
    char *title;
    char *description;
    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    int year_start;
    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    int year_end;
    char time[MAX_TIME_LENGHT];
    char *priority;
    char data_start[MAX_CALENDAR_LENGHT];
    char data_end[MAX_CALENDAR_LENGHT];
} Compromisers;


int load_compromiser(const char *cpf){
    Compromisers information;

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_LINE_LENGTH];  
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

            information.cpf = cpf_line;
            information.title = title_line;
            information.description = description_line;
            strcpy(information.data_start, data_line_start);
            strcpy(information.data_end, data_line_end);
            strcpy(information.time, time_line);
            information.priority = priority_line;

            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
            printf("| Título: %s\n", information.title);
            printf("| CPF: %s\n", information.cpf);
            printf("| Descrição: %s\n", information.description);
            printf("| Data inicial: %s\n", information.data_start);
            printf("| Data final: %s\n", information.data_end);
            printf("| Tempo: %s\n", information.time);
            printf("| Prioridade: %s\n", information.priority);            
            printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

            found = TRUE;
        }
    }

    return found;

}
