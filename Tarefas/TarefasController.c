#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TarefasController.h"
#include "TarefasView.h"
#include "TarefasModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"

int register_task(const char *file_name, const int id)
{
    limpa_buffer();

    TaskList task_list;
    Task *task = (Task *)malloc(sizeof(Task));

    if (!task)
        return FALSE;
    memset(task, 0, sizeof(Task));

    create_task_list(&task_list);
    get_task_list(&task_list, file_name);

    task->responsible_id = id;
    task->id = genetate_task_id(&task_list) + 1;
    task->status = ATIVO;

    if (!edit_task_title(task) ||
        !edit_task_description(task) ||
        !edit_task_date(task) ||
        !edit_task_type(task) ||
        !edit_task_priority(task))
    {
        free(task);
        return FALSE;
    }

    add_task_order(&task_list, task);

    int result = save_task_list(&task_list, file_name);
    free_task_list(&task_list);
    return result;
}

int search_task(TaskList *task_list, const int id, const char *name)
{
    Task *current_task = task_list->start;
    while (current_task != NULL)
    {
        if (current_task->id == id)
        {
            display_data_task(current_task, name);
            return TRUE;
        }
        current_task = current_task->next;
    }
    return FALSE;
}

int edit_task(const char *file_name, const int id)
{
    TaskList task_list;
    create_task_list(&task_list);
    get_task_list(&task_list, file_name);
    int result = FALSE;

    Task *current_task = task_list.start;

    printf("|\tID da task: ");
    int id_task;
    scanf("%d", &id_task);

    while (current_task != NULL)
    {
        if (current_task->id == id_task)
        {
            if (current_task->status == INATIVO)
            {
                show_error("Não é possível editar uma tarefa fechada.");
                return FALSE;
            }

            display_data_task(current_task, NULL);

            char option;

            do
            {
                printf("\nEditar tarefa: Escolha uma opção:\n");
                printf("[1] Título\n[2] Descrição\n[3] Data\n[4] Tipo\n[5] Prioridade\n[6] Responsável\n[7] Status\n[0] Salvar dados e sair\n");
                printf("Opção: ");
                scanf(" %c", &option);
                limpa_buffer();

                switch (option)
                {
                    case '1':
                        if (edit_task_title(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '2':
                        if (edit_task_description(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '3':
                        if (edit_task_date(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '4':
                        if (edit_task_type(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '5':
                        if (edit_task_priority(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '6':
                        if (edit_task_responsible(current_task))
                            show_sucess("Campo alterado com sucesso!");
                        else
                            show_error("Erro ao alterar o campo");
                        break;
                    case '7':
                        if (edit_task_status(current_task)){
                            show_sucess("Campo alterado com sucesso!");
                        }else{
                            show_error("Erro ao alterar o campo");
                        }
                        break;
                    case '0':
                        save_task_list(&task_list, file_name);
                        result = TRUE;
                        break;
                    default:
                        show_error("Opção inválida!");
                        break;
                }
            } while (option != '0');
            
        }
        current_task = current_task->next;
    }
    free_task_list(&task_list);

    return result;
}

int edit_task_date(Task *task)
{
    int year = year_now();
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\tData: \n");
    read_date(day, month);
    snprintf(task->date, 12, "%s/%s/%d", day, month, year);
    if (check_dates(task->date))
        return TRUE;
    return FALSE;
}

int edit_task_status(Task *task)
{
    printf("\tStatus da tarefa: \n\t[1]Ativa \n\t[2]Fechada\n");
    char status;
    scanf(" %c", &status);

    int result = FALSE;

    switch (status)
    {
    case '1':
        task->status = ATIVO;
        result = TRUE;
        break;
    case '2':
        task->status = INATIVO;
        result = TRUE;
        break;
    default:
        break;
    }

    return result;
}

int edit_task_priority(Task *task)
{
    printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
    char priority = read_generic_123("priority");
    task->priority = priority;
    return TRUE;
}

int edit_task_type(Task *task)
{
    printf("\tTipo de Tarefa: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
    char type = read_generic_123("type");
    task->type = type;
    return TRUE;
}

int edit_task_title(Task *task)
{
    printf("|\tTítulo: ");
    char *title = read_description();
    strcpy(task->title, title);
    return TRUE;
}

int edit_task_description(Task *task)
{
    printf("|\tDescrição: ");
    char *description = read_description();
    strcpy(task->description, description);
    return TRUE;
}

int edit_task_responsible(Task *task)
{
    printf("|\tResponsável:\n\t[1] Usuário\n\t[2] Equipe\n");
    char op;
    scanf(" %c", &op);
    switch (op)
    {
        case '1':
            printf("|\tID do usuário: ");
            scanf(" %d", &task->responsible_id);
            if (!user_exists(NULL, task->responsible_id))
            {
                show_error("Usuário nao encontrado!");
                return FALSE;
            }
            return TRUE;
        case '2':
            printf("|\tID do time: ");
            scanf(" %d", &task->responsible_id);
            if (!team_exists(task->responsible_id))
            {
                show_error("Time nao encontrado!");
                return FALSE;
            }
            return TRUE;
        default:
            return FALSE;
    }
    return TRUE;
}

int tasks_by_status(TaskList *list, const char status, const char *name)
{
    int result = FALSE;
    Task *current_task = list->start;
    while (current_task != NULL)
    {
        if (current_task->status == status)
        {
            result = TRUE;
            display_data_task(current_task, name);
        }
        current_task = current_task->next;
    }
    return result;
}

int show_tasks(TaskList *list, const char *name)
{
    int result = FALSE;

    Task *current_task = list->start;
    while (current_task != NULL)
    {
        result = TRUE;
        display_data_task(current_task, name);
        current_task = current_task->next;
    }
    return result;
}

int overdue_tasks(TaskList *list, const char *name)
{
    int result = FALSE;

    Task *curent_task = list->start;
    while (curent_task->next != NULL)
    {
        if (!check_dates(curent_task->date))
        {
            result = TRUE;
            display_data_task(curent_task, name);
        }
        curent_task = curent_task->next;
    }
    return result;
}

int in_progress_tasks(TaskList *list, const int id, const char *name)
{
    int result = FALSE;
    Task *current_task = list->start;
    while (current_task != NULL)
    {
        if (current_task->responsible_id == id)
        {
            result = TRUE;
            display_data_task(current_task, name);
        }
        current_task = current_task->next;
    }
    return result;
}
