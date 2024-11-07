#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

#include "TarefasModel.h"


int save_task(char *cpf, char *title, char *description, char *day, char *month, 
              char *year, char *turn, char *priority){

    if(!cpf_unique_user(cpf, "data/users.txt")){
        return FALSE;
    }

    create_path("data");

    User information;

    strcpy(information.cpf, cpf);
    strcpy(information.title, title);
    strcpy(information.description, description);
    strcpy(information.day, day);
    strcpy(information.month, month);
    strcpy(information.year, year);
    strcpy(information.turn, turn);
    strcpy(information.priority, priority);
    

    FILE *fp;
    fp = fopen("data/tasks.txt", "a");
    fprintf(fp, "%s,%s,%s,%s/%s/%s,%s,%s,3\n", information.cpf, 
                                            information.title, 
                                            information.description, 
                                            information.day, 
                                            information.month,
                                            information.year, 
                                            information.turn, 
                                            information.priority);
    fclose(fp);

    return TRUE;

}

int load_task(const char *cpf){
    User information;
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_TURN_LENGHT + MAX_PRIORITY_LENGHT + MAX_STATUS_LENGHT + 5];  // tem que adicionar turn, priority, status
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
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            printf("| CPF: %s\n", information.cpf);

            strcpy(information.title, title_line);
            printf("| Título: %s\n", information.title);

            strcpy(information.description, description_line);
            printf("| Descrição: %s\n", information.description);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information.data, data_line);
            printf("| Data: %s\n", information.data);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information.turn, turn_line);
            printf("| Turno: %s\n", information.turn);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information.priority, priority_line);
            printf("| Prioridade: %s\n", information.priority);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            
            strcpy(information.status, status_line);
            printf("| Status: %s\n", information.status);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");


            found = TRUE;
        }
    }

    return TRUE ? found : FALSE;

}