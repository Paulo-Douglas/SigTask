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
    Compromisers compromise = {NULL, NULL, NULL, NULL, NULL, NULL};
    int year = year_now();

    read_and_assign(&compromise.team_id, "|\tID: ", read_id);
    read_and_assign(&compromise.title, "|\tTítulo: ", read_string);
    read_and_assign(&compromise.description, "|\tDescrição: ", read_string);

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
    read_and_assign(&compromise.priority, "|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ", read_generic_123);

    int result = insert_compromise(&compromise);
    free_struct_compromise(&compromise);
    return result;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


int update_compromise(Compromisers *compromise, const char *id) {
    limpar_tela();
    char opc;
    int year = year_now();

    do {
        limpar_tela();
        change_data_compromisses();
        scanf(" %c", &opc);

        switch (opc) {
            case '1':
                limpa_buffer();
                printf("|\tTítulo: ");
                compromise->title = read_string();
                return update_date_compromise(&id, compromise->title, FIELD_TITLE, VARCHAR50);

            case '2':
                limpa_buffer();
                printf("|\tDescrição: ");
                compromise->description = read_description();
                return update_date_compromise(&id, compromise->description, FIELD_DESCRIPTION, VARCHAR50);
                

            case '3':
                limpa_buffer();
                printf("\t DATA INICIAL\n");
                free(compromise->start_date);
                compromise->start_date = read_and_format_date(year);
                return update_date_compromise(&id, compromise->start_date, FIELD_DATE, VARCHAR50);

            case '4':
                limpa_buffer();
                printf("\t DATA FINAL\n");
                free(compromise->end_date);
                compromise->end_date = read_and_format_date(year);
                return update_date_compromise(&id, compromise->end_date, FIELD_DATE, VARCHAR50);

            case '5':
                limpa_buffer();
                printf("|\tHorário: ");
                compromise->time = read_time();
                return update_date_compromise(&id, compromise->time, FIELD_TIME, VARCHAR50);
                

            case '6':
                limpa_buffer();
                printf("|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ");
                compromise->priority = read_generic_123("priority");
                return update_date_compromise(&id, compromise->priority, FIELD_PRIORITY, VARCHAR50);

            case '7':
                limpa_buffer();
                if(strcmp(compromise->status, "0") == 0) {show_error("| Compromisso ja fechado!\n"); return FALSE;}
                return update_date_compromise(&id, "0", FIELD_STATUS, 1);
                
            case '8':
                limpa_buffer();
                if(strcmp(compromise->status, "1") == 0) {show_error("| Compromisso ja aberto!\n"); return FALSE;}
                return update_date_compromise(&id, "1", FIELD_STATUS, 1);
                
            case '0':
                return TRUE;
            default:
                return FALSE;
        }
    } while (opc != '0');
}


void free_struct_compromise(Compromisers *compromise){
    if(compromise->title != NULL) free(compromise->title);
    if(compromise->description != NULL) free(compromise->description);
    if(compromise->start_date != NULL) free(compromise->start_date);
    if(compromise->end_date != NULL) free(compromise->end_date);
    if(compromise->time != NULL) free(compromise->time);
    if(compromise->priority != NULL) free(compromise->priority);
}

