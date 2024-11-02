#include <stdio.h>
#include <string.h>

#include "reads.h"
#include "validate.h"
#include "styles.h"
#include "utils.h"



void read_title(void) {
    limpa_buffer();
    char title[MAX_NAME_LENGTH];

    do {
        fgets(title, MAX_NAME_LENGTH, stdin);
        title[strcspn(title, "\n")] = 0;
        printf("\n");

        if (!valid_name(title)) {
            show_error("Título inválido ou muito longo (maior que 50 caracteres)");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(valid_name(title) == FALSE);
}

void read_phone(void){
    char phone[MAX_TEL_LENGTH];
    
    do{
        fgets(phone, MAX_TEL_LENGTH, stdin);
        phone[strcspn(phone, "\n")] = 0;
        printf("\n");

        if(!valid_phone(phone)){
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            limpa_buffer();
            printf("Tente novamente: ");
        }

    } while(valid_phone(phone) == FALSE);
}