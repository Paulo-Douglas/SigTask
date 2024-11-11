#include <stdio.h>
#include <string.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"

#include "CompromissosController.h"
#include "CompromissosView.h"
#include "CompromissosModel.h"


int register_compromise(void){
    char cpf[MAX_CPF_LENGTH];
    char title[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    char time[MAX_TIME_LENGHT];
    char priority[MAX_PRIORITY_LENGHT];
    int year = year_now();
    char date_complete_start[MAX_DAY_LENGHT + MAX_MONTH_LENGHT + MAX_YEAR_LENGHT];
    char date_complete_end[MAX_DAY_LENGHT + MAX_MONTH_LENGHT + MAX_YEAR_LENGHT];
    const char *data[8];

    printf("Digite o CPF: ");
    read_cpf(cpf);
    data[0] = cpf;
    
    printf("Digite o título: ");
    read_string(title);
    data[1] = title;

    printf("Digite a descrição: ");
    read_description(description);
    data[2] = description;

    printf("\t DATA INICIAL\n");
    read_date(day_start, month_start);
    snprintf(date_complete_start, sizeof(date_complete_start), "%s/%s/%d", day_start, month_start, year);
    data[3] = date_complete_start;

    printf("\t DATA FINAL\n");
    read_date(day_end, month_end);
    snprintf(date_complete_end, sizeof(date_complete_end), "%s/%s/%d", day_end, month_end, year);
    data[4] = date_complete_end;

    printf("Digite o horário: ");
    read_time(time);
    data[5] = time;

    printf("Digite a prioridade: (Baixa = 1, Média = 2, Alta = 3)");
    read_generic_123(priority);
    priority[1] = '\0';
    data[6] = priority;
    data[7] = NULL;

    return save_file(data, "data/compromisers.txt");
}

int search_compromiser_to_user(const char* cpf){

    if(cpf_unique_user(cpf, "data/users.txt")){
        return TRUE;
    } else {
        return FALSE;
    }

}

int upload_data_compromiser(const char* cpf){

    if(load_compromiser(cpf)) return TRUE;
    else return FALSE;

}