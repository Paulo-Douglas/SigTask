#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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


int load_compromise(const char *team, const char *mod){
    Compromisers compromise;

    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[LINE_COMPROMISE];
    int found = FALSE;
    int line_number = 0;

    while(fgets(line, LINE_COMPROMISE, fp) != NULL){
        if(strstr(line, team) != NULL){

            char *team_name = strtok(line, ":");
            char *title = strtok(NULL, "[");
            char *description = strtok(NULL, "]");
            char *start_date = strtok(NULL, "-");
            char *end_date = strtok(NULL, "-");
            char *time = strtok(NULL, "(");
            char *priority = strtok(NULL, ")");
            char *status = strtok(NULL, "\n");

            compromise.team_id = atoi(team_name);
            strcpy(compromise.title, title);
            strcpy(compromise.description, description);
            strcpy(compromise.start_date, start_date);
            strcpy(compromise.end_date, end_date);
            strcpy(compromise.time, time);
            strcpy(compromise.priority, priority);
            strcpy(compromise.status, status);

            if((strcmp(status, "1") == 0 || strcmp(mod, "1") == 0)){
                display_data_compromises(&compromise, line_number);
            }

            line_number++;
            getchar();
            found = TRUE;
        }
    }

    fclose(fp);
    return found;
}
