#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "reads.h"
#include "validate.h"
#include "styles.h"
#include "utils.h"

void input(char **prompt){

	char line[256];
	scanf("%255[^\n]", line);
	int tam = strlen(line);
	*prompt = (char*) malloc(tam + 1);

	if (*prompt != NULL){
		strcpy(*prompt, line);
	}

}

char *read_string(void) {
    char *string;
    int is_valid;

    do {
        input(&string);
        is_valid = validate_name(string);

        if (!is_valid) {
            show_error("[ERROR] Entrada inválida!");            
            printf("Tente novamente: ");
            free(string);
        }
    } while(!is_valid);

    limpa_buffer();
    return string;
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

        if (!validate_cpf(cpf)){
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            printf("Tente novamente: ");
        }
    } while(validate_cpf(cpf) == FALSE);
    limpa_buffer();
}

char* read_description(void) {
    char *description;
    int is_valid;
    
    do {
        input(&description);
        is_valid = validate_description(description);

        if (!is_valid){
            show_error("[ERROR] Entrada inválida!");  
            printf("Tente novamente ");
            free(description);
        
        }
    } while(!is_valid);
    limpa_buffer();
    return description;
}

void read_time(char *time){
    limpa_buffer();
    do{
        fgets(time, MAX_TIME_LENGHT, stdin);
        time[strcspn(time, "\n")] = 0;

        if (!validate_time(time)){
            show_error("Horário inválido (Formato correto: HH:MM)");    
            printf("Tente novamente: ");
        }
    } while(validate_time(time) == FALSE);
    limpa_buffer();
}

char* read_generic_123(void) {
    char *prompt = NULL;
    do {
        input(&prompt);

        if (*prompt < '1' || *prompt > '3'){
            show_error("É preciso digitar uma opção: 1, 2 ou 3\n");
            printf("Tente novamente: ");
            free(prompt);
        }
    } while (*prompt < '1' || *prompt > '3');
    limpa_buffer();
    return prompt;
}

