#ifndef TAREFASVIEW_H
#define TAREFASVIEW_H

#include "TarefasController.h"

char menu_task(void);
void add_task(void);
void search_task(void);
void change_task(void);
void delete_task(void);
void display_data_task(Task *task);
void show_all_tasks(void);
Task *struct_task(void);

#endif