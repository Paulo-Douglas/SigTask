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
    FILE *fp = fopen("data/compromisers.txt", "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%-3d:%-50s[%-100s]%-10s-%-10s(%s)%s#1\n",
        compromise->team_id,
        compromise->title,
        compromise->description,
        compromise->start_date,
        compromise->end_date,
        compromise->time,
        compromise->priority);

    fclose(fp);
    return TRUE;
}


int load_compromise(Compromisers *compromise, const char *id) {
    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[300];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp) != NULL){
        char *id_line = strtok(line, ":");
        if(id_line == NULL) continue;

        if(strcmp(id_line, id) == 0){

            char *field_number_team = strtok(NULL, ":");
            if(field_number_team == NULL) continue;
            char *number_team = strtok(NULL, ":");

            char *field_title = strtok(NULL, ":");
            if(field_title == NULL) continue;
            char *title = strtok(NULL, ",");

            char *field_description = strtok(NULL, ":");
            if(field_description == NULL) continue;
            char *description_compromisse = strtok(NULL, ",");

            char *field_date_s = strtok(NULL, ":");
            if (field_date_s == NULL) continue;     
            char *date_start = strtok(NULL, "-");
            
            char *field_date_e = strtok(NULL, ":");
            if (field_date_e == NULL) continue; 
            char *date_end = strtok(NULL, "(");     // tenho que ver colocar entre aspas aq 

            char *field_time = strtok(NULL, ":");
            if (field_time == NULL) continue;          // tenho que ver colocar entre aspas aq 
            char *time = strtok(NULL, ")");

            char *field_prio = strtok(NULL, ":");
            if(field_prio == NULL) continue;          // tenho que ver colocar entre aspas aq 
            char *prio = strtok(NULL, "#");

            char *field_status = strtok(NULL, ":");
            if(field_status == NULL) continue;            // tenho que ver colocar entre aspas aq 
            char *status = strtok(NULL, "\n");

            compromise->team_id = atoi(number_team);
            compromise->title = strdup(title);
            compromise->description = strdup(description_compromisse);
            compromise->start_date = strdup(date_start);
            compromise->end_date = strdup(date_end);
            compromise->time = strdup(time);
            compromise->priority = strdup(prio);
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
