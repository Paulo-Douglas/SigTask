#ifndef TAREFASMODEL_H
#define TAREFASMODEL_H

#define LINE_COMPROMISE 200

typedef struct task Task;

struct task
{
    int id;
    int responsible_id;
    char title[100];
    char description[100];
    char date[11];
    char type;
    char priority;
    char status;
    Task *next;
};

typedef struct
{
    Task *start;
    int lenght;
} TaskList;

void create_task_list(TaskList *list);
int genetate_task_id(TaskList *list);
void add_task_start(TaskList *list, Task *task);
void add_task_end(TaskList *list, Task *task);
void add_task_order(TaskList *list, Task *task);
void get_task_list(TaskList *list, const char *file_name);
int save_task_list(TaskList *list, const char *file_name);
void update_task_list(TaskList *list, const char *file_name);
void free_task_list(TaskList *list);

#endif