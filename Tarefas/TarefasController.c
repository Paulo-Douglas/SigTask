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


/**
 * @brief Função para atualizar um campo de uma tarefa
 * 
 * @param task Estrutura contendo os dados da tarefa.
 * @param delimiter Delimitador utilizado para identificar o campo a ser alterado.
 * @param field Campo a ser alterado.
 * @param prompt Mensagem para o usußrio.
 * @param max_length Tamanho do campo.
 * @param read_function Função para ler o dado do usußrio.
 * 
 * @return TRUE se o campo foi atualizado com sucesso, FALSE caso contrário.
 */
int update_field(Tasks *task, char delimiter, char **field, const char *prompt, int max_length, char *(*read_function)()) {
    read_and_assign(field, prompt, read_function);
    return update_data_task(task, delimiter, *field, max_length);
}


/**
 * @brief Função para registrar uma nova tarefa
 * 
 * @return TRUE se a tarefa foi registrada com sucesso, FALSE caso contrário.
 */
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
    task.priority = read_generic_123("turn");

    printf("\t PRIORIDADE\n");
    printf("|\t1 - Alta\n");
    printf("|\t2 - Média\n");
    printf("|\t3 - Baixa\n");
    task.priority = read_generic_123("priority");

    task.status = strdup("1");

    int result = insert_into_tasks("data/tasks.txt", &task);

    free_struct_task(&task);

    return result;
}


/**
 * @brief Função para buscar uma tarefa pelo CPF do usuário
 * 
 * @param cpf CPF do usuário.
 */
int search_task_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


/**
 * @brief Função para atualizar uma tarefa
 * 
 * @param task Estrutura contendo os dados da tarefa.
 * 
 * @return TRUE se a tarefa foi atualizada com sucesso, FALSE caso contrário.
 */
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


/**
 * @brief Função para atualizar o status de uma tarefa
 * 
 * @param task Estrutura contendo os dados da tarefa.
 * 
 * @param status_actual Status atual da tarefa.
 * 
 * @param message Mensagem de erro a ser exibida.
 * 
 * @param dir Diretiva que determina a operação a ser realizada: 
 *             "0" para fechar || "1" para abrir
 * 
 * @return TRUE se o status foi atualizado com sucesso, FALSE caso contrário.
 */
void update_status(
    Tasks *task,
    const char *status_actual,
    const char *message,
    const char *dir){
    task->status = strdup(status_actual);

    int result = update_status_task(task, dir);
    result ? show_sucess("| Status alterado com sucesso!\n") : show_error(message);
}


/**
 * @brief Função que libera os dados da estrutura caso existam.
 */
void free_struct_task(Tasks *task) {
    if (task->cpf != NULL) free(task->cpf);
    if (task->title != NULL) free(task->title);
    if (task->description != NULL) free(task->description);
    if (task->data != NULL) free(task->data);
    if (task->turn != NULL) free(task->turn);
    if (task->priority != NULL) free(task->priority);
    if (task->status != NULL) free(task->status);
}