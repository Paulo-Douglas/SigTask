#ifndef TAREFASCONTROLLER_H
#define TAREFASCONTROLLER_H

#include "TarefasModel.h"

int register_task(const char *file_name, const int id);
int search_task(TaskList *task_list, const int id, const char *name);
int edit_task(const char *file_name, const int id);
int edit_task_date(Task *task);
int edit_task_status(Task *task);
int edit_task_priority(Task *task);
int edit_task_type(Task *task);
int edit_task_title(Task *task);
int edit_task_description(Task *task);
int edit_task_responsible(Task *task);
int tasks_by_status(TaskList *list, const char status, const char *name);
int show_tasks(TaskList *list, const char *name);
int overdue_tasks(TaskList *list, const char *name);
int in_progress_tasks(TaskList *list, const int id, const char *name);

#endif