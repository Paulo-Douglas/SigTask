#include <stdio.h>
#include <string.h>

#include "reads.h"
#include "validate.h"
#include "styles.h"
#include "utils.h"



void read_string(char *title) {

    do {
        fgets(title, MAX_NAME_LENGTH, stdin);
        title[strcspn(title, "\n")] = 0;
        printf("\n");

        if (!valid_name(title)) {
            show_error("Inválido ou muito longo (maior que 50 caracteres)");            
            printf("Tente novamente: ");
        }
    } while(valid_name(title) == FALSE);
    limpa_buffer();
}


void read_phone(char *phone){

    do{
        fgets(phone, MAX_TEL_LENGTH, stdin);
        phone[strcspn(phone, "\n")] = 0;
        printf("\n");

        if(!valid_phone(phone)){
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            printf("Tente novamente: ");
        }

    } while(valid_phone(phone) == FALSE);
    limpa_buffer();
}


void read_cpf(char *cpf){
    do{
        fgets(cpf, MAX_CPF_LENGTH, stdin);
        printf("\n");

        if (!validation_cpf(cpf)){
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            printf("Tente novamente: ");
        }
    } while(validation_cpf(cpf) == FALSE);
    limpa_buffer();
}

void read_description(char *description) {

    do {
        fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
        description[strcspn(description, "\n")] = 0;
        printf("\n");

        if (valid_description(description) == FALSE) {
            show_error("Descricão inválida! A descrição estar entre 10 e 50 caracteres!");
            printf("Tente novamente: ");
        }
    } while(valid_description(description) == FALSE);
    limpa_buffer();
}

void read_date(char *day, char *month, char *year) {
    do {

        if (!validar_data(day, month, year)){
            show_error ("Data inválida ");
            printf("Tente novamente: ");
        }

    } while(validar_data(day, month, year) == FALSE);
    limpa_buffer();
}

void read_time(char *time){
    
    do{
        fgets(time, MAX_TIME_LENGHT, stdin);
        time[strcspn(time, "\n")] = 0;
        printf("\n");

        if (!validar_tempo(time)){
            show_error("Horário inválido (Formato correto: HH:MM)");
            printf("Tente novamente: ");
        }
    } while(validar_tempo(time) == FALSE);
    limpa_buffer();
}

void read_generic_123(char *input) {

    do {
        scanf(" %c", input);

        if (*input < '1' || *input > '3'){
            show_error("É preciso digitar uma opção: 1, 2 ou 3\n");
            printf("Tente novamente: ");
        }
    } while (*input < '1' || *input > '3');
    limpa_buffer();
}

void read_data_compromiser(char *day, char *month, char *year){ 
    do {
        if (!validar_data_alternativo(day, month)){
            show_error ("Data inválida ");
            printf("Tente novamente: ");
        }
        if (validar_data_se_fevereiro(day, month, year))  {
            printf("Qual é o ano do compromisso? ");
            scanf("%s", year);
        }
        else if (!validar_data_se_fevereiro(day, month, year)){
            show_error("Dia fora do contexto de bissexto ");
            printf("Tente novamente: ");
        }

        
        } while(validar_data(day, month, year) == FALSE || validar_data_se_fevereiro(day, month, year) == FALSE);
        limpa_buffer(); 
        
    }

