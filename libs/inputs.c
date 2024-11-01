#include <stdio.h>
#include <string.h>
#include "validate.h"
#include "utils.h"


void readPhone() {
    char telephone[15];
    int isValid = 0;

    do {
        printf("Digite o seu telefone: (XX X XXXXXXXX)\n");
        fgets(telephone, sizeof(telephone), stdin);
        telephone[strcspn(telephone, "\n")] = 0;

        isValid = validPhone(telephone);
        if (isValid == FALSE) {
            printf("\033[1;31m[ALERTA] O número informado não é válido!\033[0m\n\n");        
        }

    } while (isValid == FALSE);
}