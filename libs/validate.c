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

int validate_name(char *name) {
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

int validate_description(char *description) {
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

int validate_cpf(char cpf[]) {  
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

int cpf_unique_user(const char *cpf, const char *file){
    FILE *fp = fopen(file, "r");
    if(fp == NULL){
        return 0;
    }

    char line[MAX_CPF_LENGTH + MAX_NAME_LENGTH + MAX_TEL_LENGTH + 3];
    char cpf_user[MAX_CPF_LENGTH];

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%14[^,]", cpf_user);

        // Comparação de vetores
        if (strcmp(cpf, cpf_user) == 0) {
            fclose(fp);
            return TRUE;
        }

    }

    fclose(fp);
    return FALSE;

}

int validate_time(char tempo[]) {
    if ((tempo[0] - '0') > 2 || ((tempo[0] - '0') == 2 && (tempo[1] - '0') > 4) || 
        tempo[2] != ':' || (tempo[3] - '0') > 6 ) {
        return 0;
    } else {
        return 1;
    }
}
