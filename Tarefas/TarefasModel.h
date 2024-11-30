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


#endif