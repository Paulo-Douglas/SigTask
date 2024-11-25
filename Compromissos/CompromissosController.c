#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CompromissosController.h"
#include "CompromissosView.h"
#include "CompromissosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"



int register_compromise(void){
    limpa_buffer();
    Compromisers compromise;
    int year = year_now();

    printf("|\tEquipe: ");
    compromise.team_id = read_int();

    printf("|\tTítulo: ");
    compromise.title = read_string();

    printf("|\tDescrição: ");
    compromise.description = read_description();

    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    printf("\t DATA INICIAL\n");
    read_date(day_start, month_start);
    compromise.start_date = malloc(sizeof(char) * 12);
    snprintf(compromise.start_date, 12, "%s/%s/%d", day_start, month_start, year);

    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    printf("\t DATA FINAL\n");
    read_date(day_end, month_end);
    compromise.end_date = malloc(sizeof(char) * 12);
    snprintf(compromise.end_date, 12, "%s/%s/%d", day_end, month_end, year);

    printf("|\tHorario: ");
    compromise.time = read_time();

    printf("|\tPrioridade: ");
    compromise.priority = read_generic_123("priority");

    int result = insert_compromise(&compromise);

    return result;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


void free_strcut_compromise(Compromisers *compromise){
    if(compromise->title != NULL) free(compromise->title);
    if(compromise->description != NULL) free(compromise->description);
    if(compromise->start_date != NULL) free(compromise->start_date);
    if(compromise->end_date != NULL) free(compromise->end_date);
    if(compromise->time != NULL) free(compromise->time);
    if(compromise->priority != NULL) free(compromise->priority);
}

