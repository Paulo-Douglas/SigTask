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

    read_and_assign(&compromise.id, "|\tID: ", read_id);
    read_and_assign(&compromise.name_anything, "|\tTítulo: ", read_string);
    read_and_assign(&compromise.situation, "|\tSituação: ", read_string);
    read_and_assign(&compromise.description, "|\tDescrição: ", read_description);

    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\tData: \n");
    read_date(day, month);
    compromise.date = malloc(sizeof(char) * 12);
    snprintf(compromise.date, 12, "%s/%s/%d", day, month, year);

    int result = insert_compromise(&compromise);
    free_struct_compromise(&compromise);
    return result;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_exists(cpf);
}

int search_compromiser_to_team(const char* id){
    return id_exists(id);
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
                compromise->name_anything = read_string();
                return update_date_compromise(&id, compromise->name_anything, FIELD_TITLE, VARCHAR50);

            case '2':
                limpa_buffer();
                printf("|\tSituação: ");
                compromise->situation = read_string();
                return update_date_compromise(&id, compromise->situation, FIELD_DESCRIPTION, VARCHAR50);
                

            case '3':
                limpa_buffer();
                printf("\tData: \n");
                free(compromise->date);
                compromise->date = read_and_format_date(year);
                return update_date_compromise(&id, compromise->date, FIELD_DATE, VARCHAR50);
            
            case '4':
                limpa_buffer();
                printf("|\tDescrição: ");
                compromise->description = read_description();
                return update_date_compromise(&id, compromise->description, FIELD_DESCRIPTION, VARCHAR50);

            case '5':
                limpa_buffer();
                if(strcmp(compromise->status, "0") == 0) {show_error("| Compromisso ja fechado!\n"); return FALSE;}
                return update_date_compromise(&id, "0", FIELD_STATUS, 1);
                
            case '6':
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
    if(compromise->name_anything != NULL) free(compromise->name_anything);
    if(compromise->situation != NULL) free(compromise->situation);
    if(compromise->date != NULL) free(compromise->date);
    if(compromise->description != NULL) free (compromise->description);
}

