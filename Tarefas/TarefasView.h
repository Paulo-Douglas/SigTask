#ifndef TAREFASVIEW_H
#define TAREFASVIEW_H

#include "TarefasModel.h"

char tasks_menu(void);

void register_new_task(void);
void view_task(void);
void edit_task(void);
void delete_task(void);
void display_data_task(Tasks *task, int index, const char *id_line);

#endif