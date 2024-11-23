#ifndef TAREFASCONTROLLER_H
#define TAREFASCONTROLLER_H

#include "TarefasModel.h"

int register_task(void);
int search_task_to_user(const char* cpf);
int update_task(Tasks *task);
void update_status(
    Tasks *task,
    const char *status_actual,
    const char *message,
    const char *dir);
void read_and_assign(char **field, const char *prompt, char *(*read_function)());
int update_field(Tasks *task, char delimiter, char **field, const char *prompt, int max_length, char *(*read_function)());

#endif