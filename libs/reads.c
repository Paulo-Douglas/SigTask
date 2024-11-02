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

void read_name(void){
    char name[MAX_NAME_LENGTH];

    do{
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        printf("\n");

        if(!valid_name(name)){
            show_error("Nome inválido ou muito longo (maior que 50 caracteres)");
            limpa_buffer();
            printf("Tente novamente: ");
        }

    } while(valid_name(name) == FALSE);
}

void read_cpf(void){
    char cpf[MAX_CPF_LENGTH];

    do{
        fgets(cpf, MAX_CPF_LENGTH, stdin);
        cpf[strcspn(cpf, "\n")] = 0;
        printf("\n");

        if (!validation_cpf(cpf)){
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(validation_cpf(cpf) == FALSE);
}