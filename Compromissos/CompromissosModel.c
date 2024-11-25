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


int load_compromise(Compromisers *compromise, const char *team, const char *mod) {
    FILE *fp = fopen("data/compromisers.txt", "r");
    if(fp == NULL) return FALSE;

    char line[LINE_COMPROMISE];
    int found = FALSE;
    int line_number = 0;

    while(fgets(line, LINE_COMPROMISE, fp) != NULL) {
        if(strstr(line, team) != NULL) {

            char *number_team = strtok(line, ":");
            delete_spaces(number_team);
            char *title_compromisse = strtok(NULL, "[");
            delete_spaces(title_compromisse);
            char *description_compromisse = strtok(NULL, "]");
            delete_spaces(description_compromisse);
            char *date_start = strtok(NULL, "-");
            char *date_end = strtok(NULL, "(");
            char *time = strtok(NULL, ")");
            char *prio = strtok(NULL, "#");
            char *status = strtok(NULL, "\n");

            compromise->team_id = atoi(number_team);
            compromise->title = strdup(title_compromisse);
            compromise->description = strdup(description_compromisse);
            compromise->start_date = strdup(date_start);
            compromise->end_date = strdup(date_end);
            compromise->time = strdup(time);
            compromise->priority = strdup(prio);
            compromise->status = strdup(status);

            if((strcmp(status, "1") == 0 || strcmp(mod, "1") == 0)) {
                display_data_compromises(compromise, line_number);
            }

            line_number++;
            getchar();
            found = TRUE;
        }
    }

    fclose(fp);
    return found;
}

