#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/reads.h"
#include "../libs/date.h"

#include "TarefasController.h"
#include "TarefasModel.h"

int register_task(void){
    limpa_buffer();
    char cpf[MAX_CPF_LENGTH];
    printf("Digite o título: ");
    char *title = read_string();
    char description[MAX_DESCRIPTION_LENGTH];
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    char turn[MAX_TURN_LENGHT];
    char priority[MAX_PRIORITY_LENGHT];
    int year = year_now();
    char date_complete[MAX_DAY_LENGHT + MAX_MONTH_LENGHT + MAX_YEAR_LENGHT];
    const char *data[7];

    printf("Digite o CPF: ");
    read_cpf(cpf);
    data[0] = cpf;
    
    data[1] = title;

    printf("Digite a descrição: ");
    read_description(description);
    data[2] = description;

    printf("\t DATA\n");
    read_date(day, month);
    snprintf(date_complete, sizeof(date_complete), "%s/%s/%d", day, month, year);
    data[3] = date_complete;

    printf("Digite o turno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n");
    read_generic_123(turn);
    turn[1] = '\0';
    data[4] = turn;

    printf("Digite a prioridade: (Baixa = 3, Média = 2, Alta = 1)\n");
    read_generic_123(priority);
    priority[1] = '\0';
    data[5] = priority;

    data[6] = NULL;

    return save_file(data, "data/tasks.txt");
    
}

int search_task_to_user(const char* cpf){
    if(cpf_unique_user(cpf, "data/users.txt")){
        return TRUE;
    } else {
        return FALSE;
    }
        
}

int upload_data_task(const char* cpf){

    if(load_task(cpf)){
        return TRUE;
    } else {
        return FALSE;
    }
    return TRUE;
}