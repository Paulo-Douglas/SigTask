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

void read_description(void) {
    char description[MAX_DESCRIPTION_LENGTH];

    do {
        fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
        description[strcspn(description, "\n")] = 0;
        printf("\n");

        if (valid_description(description) == FALSE) {
            show_error("Descricão inválida! A descrição estar entre 10 e 50 caracteres!");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(valid_description(description) == FALSE);
}
