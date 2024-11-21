#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/reads.h"
#include "../libs/date.h"

#include "TarefasController.h"
#include "TarefasModel.h"

int register_task(void) {
    limpa_buffer();
    Tasks task = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    printf("|\tCPF: ");
    task.cpf = read_cpf();

    printf("|\tTítulo: ");
    task.title = read_string();

    printf("|\tDescrição: ");
    task.description = read_description();

    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    int year = year_now();
    printf("\t DATA\n");
    read_date(day, month);

    task.data = malloc(sizeof(char) * 12);
    snprintf(task.data, 12, "%s/%s/%d", day, month, year);

    limpa_buffer();
    printf("|\tTurno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n");
    char *turn_choice = read_generic_123();
    if (strcmp(turn_choice, "1") == 0) {
        task.turn = strdup("Matutino");
    } else if (strcmp(turn_choice, "2") == 0) {
        task.turn = strdup("Vespertino");
    } else {
        task.turn = strdup("Noturno");
    }
    free(turn_choice);

    printf("|\tPrioridade: (Baixa = 3, Média = 2, Alta = 1)\n");
    char *priority_choice = read_generic_123();
    if (strcmp(priority_choice, "1") == 0) {
        task.priority = strdup("Alta");
    } else if (strcmp(priority_choice, "2") == 0) {
        task.priority = strdup("Média");
    } else {
        task.priority = strdup("Baixa");
    }
    free(priority_choice);

    task.status = strdup("Aberto");

    int result = insert_into_tasks("data/tasks.txt", &task);

    free(task.cpf);
    free(task.title);
    free(task.description);
    free(task.turn);
    free(task.priority);
    free(task.status);
    free(task.data);

    return result;
}


int search_task_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}

int upload_data_task(const char* cpf){
    return load_task(cpf);
}