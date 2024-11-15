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

    char date_complete[MAX_DAY_LENGHT + MAX_MONTH_LENGHT + MAX_YEAR_LENGHT];
    const char *data[7];
    data[6] = NULL;
    int year = year_now();

    printf("Digite o CPF: ");
    char *cpf = read_cpf();
    data[0] = cpf;

    printf("Digite o título: ");
    char *title = read_string();
    data[1] = title;

    printf("Digite a descrição: ");
    char *description = read_description();
    data[2] = description;

    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\t DATA\n");
    read_date(day, month);
    snprintf(date_complete, sizeof(date_complete), "%s/%s/%d", day, month, year);
    data[3] = date_complete;

    printf("Digite o turno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n");
    char *turn = read_generic_123();
    data[4] = turn;

    printf("Digite a prioridade: (Baixa = 3, Média = 2, Alta = 1)\n");
    char *priority = read_generic_123();
    data[5] = priority;

    int result = save_file(data, "data/tasks.txt");

    free(title);
    free(description);
    free(turn);
    free(priority);
    free(cpf);

    return result;
    
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