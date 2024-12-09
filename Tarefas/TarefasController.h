#ifndef TAREFASCONTROLLER_H
#define TAREFASCONTROLLER_H

#include "TarefasModel.h"

int register_task(void);
int update_task(Tasks *task, const char *id);
void free_struct_task(Tasks *task);

#endif