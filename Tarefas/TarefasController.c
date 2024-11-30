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


int update_task(Tasks *task, const char *id) {
    char op;

    do{
        printf("|\t[1] Título\n");
        printf("|\t[2] Descrição\n");
        printf("|\t[3] Data\n");
        printf("|\t[4] Turno\n");
        printf("|\t[5] Prioridade\n");
        printf("|\t[6] Fechar\n");
        printf("|\t[7] Reabrir\n");
        printf("|\t[0] Sair\n");
        scanf(" %c", &op);
        switch (op) {

            case '1':
                limpa_buffer();
                printf("|\tTítulo: ");
                task->title = read_string();
                return update_data_task(&id, task->title, FIELD_TITLE, VARCHAR50);
            case '2':
                limpa_buffer();
                printf("|\tDescrição: ");
                task->description = read_description();
                return update_data_task(&id, task->description, FIELD_DESCRIPTION, VARCHAR50);
            case '3':
                limpa_buffer();
                int year = year_now();
                printf("|\tData: ");
                task->data = read_and_format_date(year);
                return update_data_task(&id, task->data, FIELD_DATA, 1);
            case '4':
                limpa_buffer();
                printf("|\tTurno: ");
                task->turn = read_generic_123("turn");
                return update_data_task(&id, task->turn, FIELD_TURN, 1);
            case '5':
                limpa_buffer();
                printf("|\tPrioridade: ");
                task->priority = read_generic_123("priority");
                return update_data_task(&id, task->priority, FIELD_PRIORITY, 1);
            case '6':
                limpa_buffer();
                if(strcmp(task->status, "0") == 0) {show_error("| Tarefa ja fechada!\n"); return FALSE;}
                return update_data_task(&id, "0", FIELD_STATUS, 1);
            case '7':
                limpa_buffer();
                if(strcmp(task->status, "1") == 0) {show_error("| Tarefa ja aberta!\n"); return FALSE;}
                return update_data_task(&id, "1", FIELD_STATUS, 1);
            case '0':
                return TRUE;    
            default:
                return FALSE;
        }
    } while(op != '0');
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
