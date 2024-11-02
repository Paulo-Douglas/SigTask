#include <string.h>
#include <stdio.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "UsuariosController.h"


void read_name(void){
    char name[MAX_NAME_LENGTH];

    do{
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        printf("\n");

        if(!valid_name(name)){
            show_error("Nome inválido ou muito longo (maior que 50 caracteres)");
            limpa_buffer();
            printf("Tente novamente: ");
        }

    } while(valid_name(name) == FALSE);
}

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

