#ifndef TAREFASCONTROLLER_H
#define TAREFASCONTROLLER_H

#include "TarefasModel.h"

int register_task(void);
int search_task_to_user(const char* cpf);
int update_task(Tasks *task);

#endif