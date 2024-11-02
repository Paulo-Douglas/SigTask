#include <stdio.h>
#include <string.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "TarefasController.h"


void read_description(void) {
    char description[MAX_DESCRIPTION_LENGTH];

    do {
        fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
        description[strcspn(description, "\n")] = 0;
        printf("\n");

        if (valid_description(description) == FALSE) {
            show_error("Descricão inválida! A descrição estar entre 10 e 50 caracteres!");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(valid_description(description) == FALSE);
}

void read_date(void){
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    char year[MAX_YEAR_LENGHT];

    do{
        fgets(day, MAX_DAY_LENGHT, stdin);
        day[strcspn(day, "\n")] = 0;
        printf("\n");
        fgets(month, MAX_MONTH_LENGHT, stdin);
        month[strcspn(month, "\n")] = 0;
        printf("\n");
        fgets(year, MAX_YEAR_LENGHT, stdin);
        year[strcspn(year, "\n")] = 0;
        printf("\n");

        if (!validar_data(day, month, year)){
            show_error ("Data inválida ");
            limpa_buffer();
            printf("Tente novamente: ");
    
        }

    } while(validar_data(day, month, year) == FALSE);
}

void read_turn(void) {
    char turn;
    
    scanf("%c", &turn);
    printf("\n");
}

void read_priority(void) {
    char priority;
    
    scanf("%c", &priority);
    printf("\n");
}    

void read_status(void) {
    char status;
    
    scanf("%c", &status);
    printf("\n");
}