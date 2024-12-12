#ifndef TAREFASMODEL_H
#define TAREFASMODEL_H

typedef struct
{
    char *cpf;
    char *title;
    char *description;
    char *data;  
    char *turn;
    char *priority;
    char *type;
    char *status;
} Tasks;

#define LINE_TASKS 190

int insert_into_tasks(Tasks *task);
int load_task(const char *id, Tasks *task);
int update_data_task(const char **id, const char *new_value, const char *field, int length);


#endif