#include <string.h>
#include <stdio.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "UsuariosController.h"


void read_cpf(void){
    char cpf[MAX_CPF_LENGTH];

    do{
        fgets(cpf, MAX_CPF_LENGTH, stdin);
        cpf[strcspn(cpf, "\n")] = 0;
        printf("\n");

        if (!validation_cpf(cpf)){
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            limpa_buffer();
            printf("Tente novamente: ");
        }
    } while(validation_cpf(cpf) == FALSE);
}

