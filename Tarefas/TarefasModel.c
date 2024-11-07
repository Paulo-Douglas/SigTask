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

    Tasks information;

    strcpy(information.cpf, cpf);
    strcpy(information.title, title);
    strcpy(information.description, description);
    strcpy(information.day, day);
    strcpy(information.month, month);
    strcpy(information.year, year);
    strcpy(information.turn, turn);
    strcpy(information.priority, priority);
    

    FILE *fp;
<<<<<<< HEAD
    fp = fopen("data/tasks.txt", "a");
    fprintf(fp, "%s,%s,%s,%s/%s/%s,%s,%s,3\n", information.cpf, 
                                            information.title, 
                                            information.description, 
                                            information.day, 
                                            information.month,
                                            information.year, 
                                            information.turn, 
                                            information.priority);
=======
    fp = fopen("data/users.txt", "a");
    fprintf(fp, "%s,%s,%s,%s/%s/%s,%s,%s,%s\n", information.cpf, information.title, information.description, information.day, information.month,
                                information.year, information.turn, information.priority, information.status);
>>>>>>> 79912318ecc00b6c6fa310a6bf7d657ee4a7776d
    fclose(fp);

    return TRUE;

}

int load_task(const char *cpf){
<<<<<<< HEAD
    User information;
=======
    Tasks information1;
>>>>>>> 79912318ecc00b6c6fa310a6bf7d657ee4a7776d
    
    FILE *fp = fopen("data/tasks.txt", "r");
    if(fp == NULL) return FALSE;

<<<<<<< HEAD
    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_TURN_LENGHT + MAX_PRIORITY_LENGHT + MAX_STATUS_LENGHT + 5];  // tem que adicionar turn, priority, status
=======
    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + MAX_CALENDAR_LENGHT + MAX_TURN_LENGHT + MAX_PRIORITY_LENGHT + MAX_STATUS_LENGHT + 7];  // tem que adicionar turn, priority, status
>>>>>>> 79912318ecc00b6c6fa310a6bf7d657ee4a7776d
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

            strcpy(information1.cpf, cpf_line);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            printf("| CPF: %s\n", information1.cpf);

            strcpy(information1.title, title_line);
            printf("| Título: %s\n", information1.title);

<<<<<<< HEAD
            strcpy(information.description, description_line);
            printf("| Descrição: %s\n", information.description);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information.data, data_line);
            printf("| Data: %s\n", information.data);
=======
            strcpy(information1.data, data_line);
            printf("| Data: %s/%s/%s\n", information1.day, information1.month, information1.year);
>>>>>>> 79912318ecc00b6c6fa310a6bf7d657ee4a7776d
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information1.turn, turn_line);
            printf("| Turno: %s\n", information1.turn);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");

            strcpy(information1.priority, priority_line);
            printf("| Prioridade: %s\n", information1.priority);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");
            
            strcpy(information1.status, status_line);
            printf("| Status: %s\n", information1.status);
            printf("|+------------------------+-------------------------+-------------------------+------------------------+|\n");


            found = TRUE;
        }
    }

    return TRUE ? found : FALSE;

}