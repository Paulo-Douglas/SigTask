#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "reads.h"
#include "validate.h"
#include "styles.h"
#include "utils.h"
#include "date.h"


char* read_and_format_date(int year) {
    char day[MAX_DAY_LENGHT], month[MAX_MONTH_LENGHT];
    read_date(day, month);

    char *formatted_date = malloc(sizeof(char) * 12);
    if (formatted_date != NULL) {
        snprintf(formatted_date, 12, "%s/%s/%d", day, month, year);
    }
    return formatted_date;
}


void read_and_assign(char **field, const char *prompt, char *(*read_function)()) {
    printf("%s", prompt);
    free(*field);
    *field = read_function();
}


void input(char **prompt) {
    char line[MAX_LINE_LENGTH];

    // Lê a entrada do usuário
    fgets(line, MAX_LINE_LENGTH, stdin);
    line[strcspn(line, "\n")] = '\0';

    // Aloca memória para a string e copia o conteúdo
    *prompt = (char *)malloc(strlen(line) + 1);
    if (*prompt == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    strcpy(*prompt, line);
}


char* read_string(void) {
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


int read_int(void) {
    char *input_buffer = NULL;
    char *endptr;
    int is_valid;
    int value = 0;

    do {
        input(&input_buffer);

        value = strtol(input_buffer, &endptr, 10);

        is_valid = (*endptr == '\0');

        if (!is_valid) {
            show_error("[ERROR] Entrada inválida!");
            printf("Tente novamente: ");
            free(input_buffer);
        }
    } while (!is_valid);

    free(input_buffer);

    return value;
}


char* read_phone(void){
    char *phone;

    do{
        input(&phone);

        if(!valid_phone(phone)){
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            printf("Tente novamente: ");
            free(phone);
        }

    } while(valid_phone(phone) == FALSE);
    limpa_buffer();
    return phone;
}


char* read_cpf(void){
    char *cpf = NULL;

    do{
        if (cpf != NULL){
            free(cpf);
        }

        input(&cpf);

        if (!validate_cpf(cpf)){
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            printf("Tente novamente: ");
        }

    } while(!validate_cpf(cpf));

    limpa_buffer();
    return cpf;
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

char* read_time(void){
    char *time;
    limpa_buffer();
    do{
        input(&time);

        if (!validate_time(time)){
            show_error("Horário inválido (Formato correto: HH:MM)");    
            printf("Tente novamente: ");
        }
    } while(validate_time(time) == FALSE);
    limpa_buffer();
    return time;
}

char read_generic_123(const char *dir) {
    char *prompt = NULL;
    do {
        input(&prompt);

        if (prompt == NULL || *prompt < '1' || *prompt > '3') {
            show_error("É preciso digitar uma opção: 1, 2 ou 3\n");
            printf("Tente novamente: ");
            free(prompt);
            prompt = NULL;
        }
    } while (prompt == NULL || *prompt < '1' || *prompt > '3');

    char result;
    if (strcmp(dir, "turn") == 0) {
        if (strcmp(prompt, "1") == 0) {
            result = 'M';
        } else if (strcmp(prompt, "2") == 0) {
            result = 'V';
        } else {
            result = 'N';
        }
    } else if (strcmp(dir, "priority") == 0) {
        if (strcmp(prompt, "1") == 0) {
            result = 'A';
        } else if (strcmp(prompt, "2") == 0) {
            result = 'M';
        } else {
            result = 'B';
        }
    } else if (strcmp(dir, "type") == 0) {
        if (strcmp(prompt, "1") == 0) {
            result = 'E';
        } else if (strcmp(prompt, "2") == 0) {
            result = 'R';
        } else {
            result = 'P';
        }
    }
    free(prompt);

    return result;
}

char* read_id(void){
    char *id;
    int is_valid = FALSE;

    do { 
        input(&id);

        if(!isdigit(id)){
            show_error("Digite apenas números: \n");
            printf("Tente novamente");
        } else {
            is_valid = TRUE;
        }
    } while (!is_valid);

    return id;
}