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

int insert_into_tasks(const char* file_name, Tasks *task);
int load_task(const char *cpf);

#endif