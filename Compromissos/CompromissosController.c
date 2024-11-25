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

    printf("|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ");
    compromise.priority = read_generic_123("priority");

    int result = insert_compromise(&compromise);

    return result;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


int update_crompromise(Compromisers *compromise, char *id) {
    char opc;
    int result;
    int year = year_now();

    do {
        printf("| Escolha uma opção para alterar: \n\t(1) Titulo\n\t(2) Descrição\n\t(3) Data inicial\n\t(4) Data final\n\t(5) Horário\n\t(6) Priopridade\n\t(7) Fechar compromisso\n\t(0) Sair: \n");
        opc = getchar();
        limpa_buffer();

        switch (opc) {
            case '1':
                printf("|\tTitulo: ");
                compromise->title = read_string();
                result = update_date_compromise(':', compromise->title, 50, *id);
                break;
            case '2':
                printf("|\tDescrição: ");
                compromise->description = read_description();
                result = update_date_compromise('[', compromise->description, 100, *id);
                break;
            case '3':
                char day_start[MAX_DAY_LENGHT];
                char month_start[MAX_MONTH_LENGHT];
                printf("\t DATA INICIAL\n");
                read_date(day_start, month_start);
                compromise->end_date = malloc(sizeof(char) * 10);
                snprintf(compromise->end_date, 12, "%s/%s/%d", day_start, month_start, year);
                result = update_date_compromise(']', compromise->end_date, 10, *id);
                break;
            case '4':
                char day_end[MAX_DAY_LENGHT];
                char month_end[MAX_MONTH_LENGHT];
                printf("\t DATA FINAL\n");
                read_date(day_end, month_end);
                compromise->end_date = malloc(sizeof(char) * 12);
                snprintf(compromise->end_date, 12, "%s/%s/%d", day_end, month_end, year);
                result = update_date_compromise('-', compromise->end_date, 10, *id);
                break;
            case '5':
                printf("|\tHorario: ");
                compromise->time = read_time();
                result = update_date_compromise('(', compromise->time, 5, *id);
                break;
            case '6':
                printf("|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ");
                compromise->priority = read_generic_123("priority");
                result = update_date_compromise(')', compromise->priority, 1, *id);
                break;
            case '7':
                result = update_date_compromise('#', "0", 1, *id);
                break;
            case '0':
                break;
            default:
                break;
        }
    } while (opc != 0);

    return FALSE;
}


void free_strcut_compromise(Compromisers *compromise){
    if(compromise->title != NULL) free(compromise->title);
    if(compromise->description != NULL) free(compromise->description);
    if(compromise->start_date != NULL) free(compromise->start_date);
    if(compromise->end_date != NULL) free(compromise->end_date);
    if(compromise->time != NULL) free(compromise->time);
    if(compromise->priority != NULL) free(compromise->priority);
}

