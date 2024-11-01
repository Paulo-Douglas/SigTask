#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "utils.h"


int validPhone(char *telephone) {
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