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
    Compromisers compromise = {0};
    int year = year_now();

    read_and_assign(&compromise.team_id, "|\tTime: ", read_int);
    read_and_assign(&compromise.title, "|\tTítulo: ", read_string);
    read_and_assign(&compromise.description, "|\tDescrição: ", read_description);

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

    read_and_assign(&compromise.time, "|\tHorário: ", read_time);
    printf("\t PRIORIDADE\n");
    printf("|\t1 - Alta\n");
    printf("|\t2 - Média\n");
    printf("|\t3 - Baixa\n");
    compromise.priority = read_generic_123("priority");

    free_strcut_compromise(&compromise);

    return FALSE;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


int upload_data_compromiser(const char* cpf){
    return load_compromise(cpf);
}


void free_strcut_compromise(Compromisers *compromise) {
    if (compromise->team_id != NULL) {
        free(compromise->team_id);
        compromise->team_id = NULL;
    }
    if (compromise->title != NULL) {
        free(compromise->title);
        compromise->title = NULL;
    }
    if (compromise->description != NULL) {
        free(compromise->description);
        compromise->description = NULL;
    }
    if (compromise->start_date != NULL) {
        free(compromise->start_date);
        compromise->start_date = NULL;
    }
    if (compromise->end_date != NULL) {
        free(compromise->end_date);
        compromise->end_date = NULL;
    }
    if (compromise->time != NULL) {
        free(compromise->time);
        compromise->time = NULL;
    }
    if (compromise->priority != NULL) {
        free(compromise->priority);
        compromise->priority = NULL;
    }
}
