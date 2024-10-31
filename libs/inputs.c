#include <stdio.h>
#include <string.h>
#include "validate.h"


void validateTelephone(void) {
    char telephone[14];
    int isValid = 0;

    do {
        printf("Digite o seu telefone: (XX X XXXXXXXX)\n");
        fgets(telephone, sizeof(telephone), stdin);
        telephone[strcspn(telephone, "\n")] = 0;

        isValid = validTelephone(telephone);
        if (isValid) {
            return;
        } else {
            printf("%s não é um número de telefone válido. Digite novamente!\n", telephone);
        }

    } while (!isValid);
}