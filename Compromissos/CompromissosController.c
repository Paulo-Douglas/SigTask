#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"

#include "CompromissosController.h"
#include "CompromissosView.h"
#include "CompromissosModel.h"


int register_compromise(void){
    limpa_buffer();
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|                              REGISTRO DE COMPROMISSOS                             |\n");
    const char *data[8];
    data[7] = NULL;
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

    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    char date_complete_start[MAX_CALENDAR_LENGHT];
    printf("\t DATA INICIAL\n");
    read_date(day_start, month_start);
    snprintf(date_complete_start, sizeof(date_complete_start), "%s/%s/%d", day_start, month_start, year);
    data[3] = date_complete_start;

    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    char date_complete_end[MAX_CALENDAR_LENGHT];
    printf("\t DATA FINAL\n");
    read_date(day_end, month_end);
    snprintf(date_complete_end, sizeof(date_complete_end), "%s/%s/%d", day_end, month_end, year);
    data[4] = date_complete_end;

    char time[MAX_TIME_LENGHT];
    printf("Digite o horário: ");
    read_time(time);
    data[5] = time;

    printf("Digite a prioridade: (Baixa = 1, Média = 2, Alta = 3)");
    char *priority = read_generic_123("priority");
    data[6] = priority;
    printf("|-----------------------------------------------------------------------------------|\n");


    int result = save_file(data, "data/compromisers.txt");

    free(title);
    free(description);
    free(priority);
    free(cpf);

    return result;
}

int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}

int upload_data_compromiser(const char* cpf){
    return load_compromiser(cpf);
}

