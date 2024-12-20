#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "TarefasModel.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int get_id_task(void){
    FILE * fp = fopen("data/task.dat", "rb");
    if (fp == NULL) return FALSE;

    Task task;
    int next_id = 1;

    fseek(fp, -sizeof(Task), SEEK_END);

    if (fread(&task, sizeof(Task), 1, fp)){
        next_id = atoi(task.id) + 1;
    }

    fclose(fp);
    return next_id;
}


int insert_task(Task *task){
    int id = get_id_task();
    if (id == 0) id = 1;

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

void show_tasks(const char status, const char *key){
    FILE *fp = fopen("data/task.dat", "rb");
    if(fp == NULL) return;

    Task task;
    while (fread(&task, sizeof(Task), 1, fp)) {
        // Condição para exibir todos os registros
        if (strcmp(key, "all") == 0) {
            display_data_task(&task);
            continue;
        }

        if (status == '\0' || status == task.status) {
            if (strcmp(key, "status") == 0) {
                display_data_task(&task);
            } else if (strcmp(key, "users") == 0 && strchr(task.id, 'U') != NULL) {
                display_data_task(&task);
            } else if (strcmp(key, "team") == 0 && strchr(task.id, 'T') != NULL) {
                display_data_task(&task);
            }
        }
    }

    fclose(fp);

}
 