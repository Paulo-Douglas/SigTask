#include <stdio.h>
#include <string.h>
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