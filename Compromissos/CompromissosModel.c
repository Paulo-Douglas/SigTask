#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "CompromissosModel.h"

int save_compromiser(char *cpf, char *title, char *description, char *day_start, char *month_start,
                     char *year_start, char *day_end, char *month_end, char *year_end, char *time, char *priority){


    if(!cpf_unique_user(cpf, "data/users.txt")){
        return FALSE;
    }

    create_path("data");

    Compromisers information;

    strcpy(information.cpf, cpf);
    strcpy(information.title, title);   
    strcpy(information.description, description);
    strcpy(information.day_start, day_start);
    strcpy(information.month_start, month_start);
    strcpy(information.year_start, year_start);
    strcpy(information.day_end, day_end);
    strcpy(information.month_end, month_end);
    strcpy(information.year_end, year_end);
    strcpy(information.time, time);
    strcpy(information.priority, priority);
    

    FILE *fp;   
    fp = fopen("data/compromisers.txt", "a");
    fprintf(fp, "%s,%s,%s,%s/%s/%s,%s/%s/%s,%s,%s\n", information.cpf, information.title, information.description, information.day_start, information.month_start,
                                information.year_start, information.day_end, information.month_end, information.year_end ,information.time, information.priority);
    fclose(fp);

    return TRUE;

}

int load_compromiser(const char *cpf){
    Compromisers information;

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_CALENDAR_LENGHT + MAX_TIME_LENGHT + MAX_PRIORITY_LENGHT + 7];  
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

    return TRUE ? found : FALSE;

}
