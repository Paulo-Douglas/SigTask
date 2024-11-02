#include <stdio.h>
#include <string.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "CompromissosController.h"
#include "CompromissosView.h"


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

void read_priority(void) {
    char priority;
    
    scanf("%c", &priority);
    printf("\n");
}

void read_time(void){
    char tempo[MAX_TIME_LENGHT];
    
    do{
        fgets(tempo, MAX_TIME_LENGHT, stdin);
        tempo[strcspn(tempo, "\n")] = 0;
        printf("\n");

        if (!validar_tempo(tempo)){
            show_error("Horário inválido (Formato correto: HH:MM)");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(validar_tempo(tempo) == FALSE);
}