#include <stdio.h>
#include <string.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "CompromissosController.h"
#include "CompromissosView.h"


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