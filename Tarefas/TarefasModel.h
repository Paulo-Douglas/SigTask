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

#define LINE_TASKS 185

int insert_into_tasks(const char* file_name, Tasks *task);
int load_task(const char *cpf, Tasks *task);
int update_title_task(Tasks *task);

#endif