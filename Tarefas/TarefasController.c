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
    task.turn = read_generic_123("turn");

    printf("|\tPrioridade: (Baixa = 3, Média = 2, Alta = 1)\n");
    task.priority = read_generic_123("priority");

    task.status = strdup("1");

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


int update_task(Tasks *task){
    char opc;
    int result = FALSE;

    do{
        printf("Escolha um campo para alterar:\n");
        printf("1 - Título\n");
        printf("2 - Descrição\n");
        printf("3 - Data\n");
        printf("4 - Turno\n");
        printf("5 - Prioridade\n");
        printf("6 - Status\n");
        printf("0 - Sair\n");
        opc = getchar();
        getchar();

        switch(opc){
            case '1':
                printf("|\tTítulo: ");
                task->title = read_string();
                result = update_title_task(task);
                if(result) show_sucess("| Título alterado com sucesso!\n");
                break;
            case '0':
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opc != '0');

    return result;
}