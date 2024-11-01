#include <stdio.h>
#include <string.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "TarefasController.h"


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

