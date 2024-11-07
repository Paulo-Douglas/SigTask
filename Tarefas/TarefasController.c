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

    printf("Digite o CPF: ");
    read_cpf(cpf);
    
    printf("Digite o título: ");
    read_string(title);

    printf("Digite a descrição: ");
    read_description(description);

    printf("Digite o dia: ");
    scanf(" %s", day);
    printf("Digite o mês: ");
    scanf(" %s", month);
    printf("Digite o ano: ");
    scanf(" %s", year);
    read_date(day, month, year);

    printf("Digite o turno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n");
    read_generic_123(turn);

    printf("Digite a prioridade: (Baixa = 3, Média = 2, Alta = 1)\n");
    read_generic_123(priority);

    if(!save_task(cpf, title, description, day, month, year, turn, priority)){
        return FALSE;
    };
    return TRUE;

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