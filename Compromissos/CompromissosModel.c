#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "CompromissosModel.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/utils.h"


int insert_compromise(Compromisers *compromise){
    create_path("data/");


    FILE *fp = fopen("data/compromisers.txt", "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:{", compromise->id);
    fprintf(fp, "%s%-*s,", FIELD_TITLE, VARCHAR50, compromise->name_anything);
    fprintf(fp, "%s%-*s,", FIELD_TITLE, VARCHAR50, compromise->situation);
    fprintf(fp, "%s%s,", FIELD_DATE, compromise->date);
    fprintf(fp, "%s%-*s,", FIELD_DESCRIPTION, VARCHAR50, compromise->description);
    fprintf(fp, "}\n");

    fclose(fp);
    return TRUE;
}


int load_compromise(const char *id, Compromisers *compromise) {
    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[300];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) != NULL){
        char *id_line = strtok(line, ":");
        if(id_line == NULL) continue;

        if(strcmp(id_line, id) == 0){

            char *field_number_anything = strtok(NULL, ":");
            if(field_number_anything == NULL) continue;
            char *number_anything = strtok(NULL, ":");

            char *field_name = strtok(NULL, ":");
            if(field_name == NULL) continue;
            char *name_all = strtok(NULL, ",");

            char *field_situation = strtok(NULL, ":");
            if(field_situation == NULL) continue;
            char *type_situation = strtok(NULL, ",");

            char *field_date = strtok(NULL, ":");
            if (field_date == NULL) continue;     
            char *date_compromise = strtok(NULL, "-");

            char *field_description = strtok(NULL, ":");
            if (field_description == NULL) continue;
            char *description_compromise = strtok(NULL, "\n");
            
            char *field_status = strtok(NULL, ":");
            if(field_status == NULL) continue;            // tenho que ver colocar entre aspas aq 
            char *status = strtok(NULL, "\n");

            compromise->id = strdup(number_anything);
            compromise->name_anything = strdup(name_all);
            compromise->situation = strdup(type_situation);
            compromise->date = strdup(date_compromise);
            compromise->description = strdup(description_compromise);
            compromise->status = strdup(status);

            found = TRUE;
            break;
        } 
    }

    fclose(fp);
    return found;
}


int update_date_compromise(const char **id, const char *new_value, const char *field, int length){
    FILE *fp = fopen("data/compromisers.txt", "r+");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    memset(line, 0, sizeof(line));
    int found_id = 0;
    long pos = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, *id) != NULL) {
            found_id = 1;
        }

        if (found_id && strstr(line, field) != NULL) {
            char *field_pos = strstr(line, field);
            if (field_pos == NULL) break;

            pos = ftell(fp) - strlen(line) + (field_pos - line) + strlen(field);
            fseek(fp, pos, SEEK_SET);

            fprintf(fp, "%-*s", length, new_value);

            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
