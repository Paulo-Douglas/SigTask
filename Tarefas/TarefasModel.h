#ifndef TAREFASMODEL_H
#define TAREFASMODEL_H

#define LINE_COMPROMISE 200

typedef struct
{
    char id[4];
    char responsible[4];
    char title[100];
    char description[100];
    char date[11];
    char type;
    char priority;
    char status;

} Task;

void show_tasks(void);

int insert_task(Task *task);
int get_id_task(void);
int update_task(Task *task);
Task * load_task(const char *id);

#endif