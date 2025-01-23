#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "TarefasModel.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"

void create_task_list(TaskList *list)
{
    list->start = NULL;
    list->lenght = 0;
}

int genetate_task_id(TaskList *list)
{
    int max_id = 0;

    Task *current = list->start;
    while (current != NULL)
    {
        if (current->id > max_id)
            max_id = current->id;
        current = current->next;
    }

    return max_id;
}

void add_task_start(TaskList *list, Task *task)
{
    task->next = list->start;
    list->start = task;
    list->lenght++;
}

void add_task_end(TaskList *list, Task *task)
{
    if (list->start == NULL)
        add_task_start(list, task);
    else
    {
        Task *aux = list->start;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = task;
    }
    list->lenght++;
}

void add_task_order(TaskList *list, Task *task)
{
    if (list->start == NULL || compare_dates(task->date, list->start->date) == 1)
        add_task_start(list, task);
    else
    {
        Task *aux = list->start;
        while (aux->next != NULL && compare_dates(task->date, aux->next->date) == -1)
            aux = aux->next;
        task->next = aux->next;
        aux->next = task;
    }
}

void get_task_list(TaskList *list, const char *file_name)
{
    FILE *fp = fopen(file_name, "rb");
    if (!fp)
        return;

    while (!feof(fp))
    {
        Task *new_task = (Task *)malloc(sizeof(Task));
        if (fread(new_task, sizeof(Task), 1, fp) != 1)
        {
            free(new_task);
            break;
        }
        new_task->next = NULL;
        add_task_end(list, new_task);
    }
    fclose(fp);
}

int save_task_list(TaskList *list, const char *file_name)
{
    create_path("data/");
    FILE *fp = fopen(file_name, "wb");
    if (!fp)
        return FALSE;

    Task *aux = list->start;
    while (aux != NULL)
    {
        fwrite(aux, sizeof(Task), 1, fp);
        aux = aux->next;
    }
    fclose(fp);
    return TRUE;
}

void update_task_list(TaskList *list, const char *file_name)
{
    FILE *fp = fopen(file_name, "wb");
    if (!fp)
        return;

    Task *aux = list->start;
    while (aux != NULL)
    {
        fwrite(aux, sizeof(Task), 1, fp);
        aux = aux->next;
    }
    fclose(fp);
}

void free_task_list(TaskList *list)
{
    Task *aux = list->start;
    while (aux != NULL)
    {
        Task *next = aux->next;
        free(aux);
        aux = next;
    }
}