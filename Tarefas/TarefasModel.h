#ifndef TAREFASMODEL_H
#define TAREFASMODEL_H

typedef struct
{
    char *cpf;
    char *title;
    char *description;
    char *turn;
    char *priority;
    char *status;
    char *data;  
} Tasks;

#define LINE_TASKS 190

int insert_into_tasks(Tasks *task);
int load_task(const char *id, Tasks *task);

int update_status_task(Tasks *task, const char *dir);
int update_data_task(Tasks *task, const char delimit, const char *new_data, const int lenght);

#endif