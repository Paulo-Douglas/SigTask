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
    int year = year_now();

    Compromisers compromise = {0};

    printf("|\tTítulo: ");
    char *title = read_string();
    strcpy(compromise.title, title);

    printf("|\tDescrição: ");
    char *description = read_string();
    strcpy(compromise.description, description);

    limpa_buffer();
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\tData: \n");
    read_date(day, month);
    snprintf(compromise.date, 12, "%s/%s/%d", day, month, year);

    limpa_buffer();
    printf("\tTipo de compromisso: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
    char type = read_generic_123("type");
    compromise.type = type;

    printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
    char priority = read_generic_123("priority");
    compromise.priority = priority;

    compromise.status = '1';

    int result = insert_compromise(&compromise);

    return result;
}



// void free_struct_compromise(Compromisers *compromise){
//     if(compromise->name_anything != NULL) free(compromise->name_anything);
//     if(compromise->situation != NULL) free(compromise->situation);
//     if(compromise->date != NULL) free(compromise->date);
//     if(compromise->description != NULL) free (compromise->description);
// }

