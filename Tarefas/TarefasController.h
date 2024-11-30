#ifndef TAREFASCONTROLLER_H
#define TAREFASCONTROLLER_H

#include "TarefasModel.h"

int register_task(void);
int search_task(Tasks *task);

void free_struct_task(Tasks *task);

#endif