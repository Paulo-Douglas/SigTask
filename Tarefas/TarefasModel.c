#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "TarefasModel.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int insert_task(Task *task){
    int id = get_next_id("data/task.dat");
    if(id == 0) id = 1;

    snprintf(task->id, sizeof(task->id), "%d", id);

    create_path("data/");
    int result = FALSE;

    FILE *fp = fopen("data/task.dat", "ab");
    if(fp == NULL) return result;

    if (fwrite(task, sizeof(Task), 1, fp)) result = TRUE;

    fclose(fp);
    return result;
}

Task * load_task(const char *id){
    FILE *fp = fopen("data/task.dat", "rb");
    if(fp == NULL) return NULL;

    Task *task = (Task *)malloc(sizeof(Task));
    while(fread(task, sizeof(Task), 1, fp)){
        getchar();
        if(strcmp(task->id, id) == 0){
            fclose(fp);
            return task;
        }
    }
    fclose(fp);
    free(task);
    return NULL;

}

int update_task(Task *new_task){
    FILE *fp = fopen("data/task.dat", "rb+");
    if(fp == NULL) return FALSE;

    Task task;
    while(fread(&task, sizeof(Task), 1, fp)){
        if(strcmp(task.id, new_task->id) == 0){
            fseek(fp, -sizeof(Task), SEEK_CUR);
            fwrite(new_task, sizeof(Task), 1, fp);
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}
