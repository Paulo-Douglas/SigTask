#include <stdio.h>
#include <string.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/reads.h"
#include "TarefasController.h"
#include "TarefasModel.h"

int register_task(void){
    char cpf[MAX_CPF_LENGTH];
    char title[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    char year[MAX_YEAR_LENGHT];
    char turn[2];
    char priority[2];
    char status[2];

    printf("Digite o CPF: ");
    read_cpf(cpf);
    
    printf("Digite o título: ");
    read_string(title);

    printf("Digite a descrição: ");
    read_description(description);

    printf("Digite a data: ");
    printf("Digite o mês: ");
    printf("Digite o ano: ");
    read_date(day, month, year);

    printf("Digite o turno: (Matutino = M, Vespertino = V, Noturno = N e Integral= I)");
    read_generic_123(priority);

    printf("Digite a prioridade: (Baixa = B, Média = M, Alta = A)");
    read_generic_123(priority);
    return save_task(cpf, title, description, day, month, year, turn, priority, status);
}

int search_task(const char* cpf){
    if(cpf_unique_user(cpf, "data/users.txt")){
        return TRUE;
    } else {
        return FALSE;
    }
        
}

int upload_data_task(const char* cpf){
    printf("Tarefas carregadas com sucesso!\n");
    return TRUE;
}