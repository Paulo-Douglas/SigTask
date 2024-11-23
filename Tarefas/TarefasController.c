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


int update_field(Tasks *task, char delimiter, char **field, const char *prompt, int max_length, char *(*read_function)()) {
    read_and_assign(field, prompt, read_function);
    return update_data_task(task, delimiter, *field, max_length);
}


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
    read_and_assign(&task.turn, "|\tTurno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n", read_generic_123);
    read_and_assign(&task.priority, "|\tPrioridade: (Baixa = 3, Média = 2, Alta = 1)\n", read_generic_123);
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
        printf("|   Escolha um campo para alterar:\n");
        printf("|   1 - Título\n");
        printf("|   2 - Descrição\n");
        printf("|   3 - Data\n");
        printf("|   4 - Turno\n");
        printf("|   5 - Prioridade\n");
        printf("|   6 - Fechar Tarefa\n");
        printf("|   7 - Reativar Tarefa\n");
        printf("|   0 - Sair\n");
        scanf(" %c", &opc);
        getchar();
        /*
            title 50 delimit -> :
            description 100 delimit -> [
            data 10 -> delimit -> ]
            turn 1 -> delimit -> ;
            priority 1 -> delimit -> (
        */

        switch(opc){
            case '1':
                result = update_field(task, ':', &task->title, "|\tTítulo: ", 50, read_string);                
                if(result) show_sucess("| Título alterado com sucesso!\n");
                break;
            case '2':
                result = update_field(task, '[', &task->description, "|\tDescrição: ", 100, read_description);
                if(result) show_sucess("| Descrição alterada com sucesso!\n");
                break;
            case '3':
                char day[MAX_DAY_LENGHT];
                char month[MAX_MONTH_LENGHT];
                int year = year_now();
                printf("\t DATA\n");
                read_date(day, month);

                task->data = malloc(sizeof(char) * 12);
                snprintf(task->data, 12, "%s/%s/%d", day, month, year);

                result = update_data_task(task, ']', task->data, 10);
                if(result) show_sucess("| Data alterada com sucesso!\n");
                break;
            case '4':
                result = update_field(task, ';', &task->turn, "|\tTurno: (Matutino = 1, Vespertino = 2 e Noturno = 3)\n", 1, read_generic_123);
                if (result) show_sucess("| Turno alterado com sucesso!\n");
                break;
            case '5':
                result = update_field(task, '(', &task->priority, "|\tPrioridade: (Baixa = 3, Média = 2, Alta = 1)\n", 1, read_generic_123);
                if (result) show_sucess("| Prioridade alterada com sucesso!\n");
                break;
            case '6':
                update_status(task, "0", "| [ERRO]: Tarefa já fechada!\n", "close");
                limpa_buffer();
                break;
            case '7':
                update_status(task, "1", "| [ERRO]: Tarefa já aberta!\n", "open");
                limpa_buffer();
                break;
            case '0':
                limpa_buffer();
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opc != '0');

    return result;
}


void update_status(
    Tasks *task,
    const char *status_actual,
    const char *message,
    const char *dir){
    task->status = strdup(status_actual);

    int result = update_status_task(task, dir);
    result ? show_sucess("| Status alterado com sucesso!\n") : show_error(message);
}
