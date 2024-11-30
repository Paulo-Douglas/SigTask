#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TarefasController.h"
#include "TarefasModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/reads.h"
#include "../libs/date.h"


int register_task(void) {
    limpa_buffer();
    Tasks task = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    read_and_assign(&task.cpf, "|\tCPF: ", read_cpf);
    read_and_assign(&task.title, "|\tTarefa: ", read_string);
    read_and_assign(&task.description, "|\tDescrição: ", read_description);

    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    int year = year_now();
    printf("\t DATA\n");
    read_date(day, month);

    task.data = malloc(sizeof(char) * 12);
    snprintf(task.data, 12, "%s/%s/%d", day, month, year);

    limpa_buffer();
    printf("\t TURNO\n");
    printf("|\t1 - Matutino\n");
    printf("|\t2 - Vespertino\n");
    printf("|\t3 - Noturno\n");
    task.turn = read_generic_123("turn");

    printf("\t PRIORIDADE\n");
    printf("|\t1 - Alta\n");
    printf("|\t2 - Média\n");
    printf("|\t3 - Baixa\n");
    task.priority = read_generic_123("priority");

    task.status = strdup("1");

    if(task.cpf == NULL || task.title == NULL || task.description == NULL || task.data == NULL || task.turn == NULL || task.priority == NULL) return FALSE;

    int result = insert_into_tasks(&task);

    free_struct_task(&task);

    return result;
}


int search_task(Tasks *task) {
    char id;
    printf("|\tInforme o ID da tarefa:\t");
    scanf(" %c", &id);

    return load_task(&id, task);
}


void free_struct_task(Tasks *task) {
    if (task->cpf != NULL) free(task->cpf);
    if (task->title != NULL) free(task->title);
    if (task->description != NULL) free(task->description);
    if (task->data != NULL) free(task->data);
    if (task->turn != NULL) free(task->turn);
    if (task->priority != NULL) free(task->priority);
    if (task->status != NULL) free(task->status);
}
