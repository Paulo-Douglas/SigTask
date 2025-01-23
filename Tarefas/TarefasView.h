#ifndef TAREFASVIEW_H
#define TAREFASVIEW_H

#include "TarefasController.h"

typedef struct
{
    const char *file_name;
    int id;
} TaskInfo;

int get_task_info(TaskInfo *task_info);
char menu_task(void);
void menu_task_register(void);
void menu_task_search(void);
void menu_task_edit(void);
void menu_task_reports(void);
void display_data_task(Task *task, const char *name);
int chose_task_to_show();

#endif