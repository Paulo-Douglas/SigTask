#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "utils.h"
#include "validate.h"

int length_prompt(char *prompt, int maxLength, int minLength) {
    if (strlen(prompt) > maxLength || strlen(prompt) < minLength) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int valid_phone(char *telephone) {
    // Cria um objeto Regex
    regex_t phoneRegex;
    // Expressão regular para validar o telefone
    const char *standardPhone = "^[0-9]{2} [0-9]{1} [0-9]{8}$";
    int reti;

    // Compila a expressão regular
    reti = regcomp(&phoneRegex, standardPhone, REG_EXTENDED);
    if (reti) {
        return FALSE;
    }

    reti = regexec(&phoneRegex, telephone, 0, NULL, 0);
    regfree(&phoneRegex);  // Libera a memória após uso

    return reti == 0 ? TRUE : FALSE;
}

int valid_name(char *name) {
    if (strlen(name) > MAX_NAME_LENGTH) {
        return FALSE;
    }

    regex_t nameRegex;
    const char *standardName = "^[A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú]+( [A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú]+)*$";
    int reti;

    reti = regcomp(&nameRegex, standardName, REG_EXTENDED);
    if(reti){
        return FALSE;
    }

    reti = regexec(&nameRegex, name, 0, NULL, 0);
    regfree(&nameRegex);
    

    return reti == 0 ? TRUE : FALSE;
}

int valid_description(char *description) {
    if(length_prompt(description, MAX_DESCRIPTION_LENGTH, MIN_DESCRIPTION_LENGTH) == TRUE) {
        return FALSE;
    }

    regex_t descriptionRegex;
    const char *standardDescription = "^[A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú.,!?-]+( [A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú.,!?-]+)*$";    
    int reti;

    reti = regcomp(&descriptionRegex, standardDescription, REG_EXTENDED);
    if(reti){
        return FALSE;
    }

    reti = regexec(&descriptionRegex, description, 0, NULL, 0);
    regfree(&descriptionRegex);

    return reti == 0 ? TRUE : FALSE;
}

int validation_cpf(char cpf[]) {                    // peguei o cálculo de https://dicasdeprogramacao.com.br/algoritmo-para-validar-cpf/
        int calcule_one_dig = 0;  
        int calcule_second_dig = 0;
        int x = 14;
        
        calcule_one_dig  = (cpf[0] - '0') * 10 + (cpf[1] - '0') * 9 + 
                (cpf[2] - '0') * 8 + (cpf[4] - '0') * 7 +                               // aqui faço pulo de indices para dar espaço 
                (cpf[5] - '0') * 6 + (cpf[6] - '0') * 5 +                               // para os indices 3, 7, 11 (para pontuação)
                (cpf[8] - '0') * 4 + (cpf[9] - '0') * 3 + 
                (cpf[10] - '0') * 2;


        calcule_second_dig = (cpf[0] - '0') * 11 + (cpf[1] - '0') * 10 + 
                (cpf[2] - '0') * 9 + (cpf[4] - '0') * 8 + 
                (cpf[5] - '0') * 7 + (cpf[6] - '0') * 6 + 
                (cpf[8] - '0') * 5 + (cpf[9] - '0') * 4 + 
                (cpf[10] - '0') * 3 + (cpf[12] - '0') * 2;
        
        if (((calcule_one_dig  * 10) % 11 == (cpf[12] - '0')) &&  (calcule_second_dig * 10) % 11 == (cpf[13] - '0') && (strlen(cpf) >= x)
            && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-') {
            return 1;
        }    
        else {
            return 0;
    }   
    }

int bissexto(char year[]) {
    int ano = atoi(year); // para lidar com ela como se fosse um inteiro 
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    }
    return 0;
}

int dia_mes(int mês) {
    int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dias_por_mes[mês];
}

int validar_data(char day[], char month[], char year[]){
    int dia = atoi(day);
    int mês = atoi(month);
    if (mês < 1 || mês > 12) {
        return 0; // limitação de meses
    }
    int maior_dia = dia_mes(mês);

    if (mês == 2) { // quando for fevereiro
        if (bissexto(year)) {
            maior_dia = 29;
        } else {
            maior_dia = 28;
        }
    }
    return dia <= maior_dia;
}