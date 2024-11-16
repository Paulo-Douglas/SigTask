#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"

#include "EquipeModel.h"

typedef struct
{
  char *team_name;
  char *description;
} Team;



int view_team(char *name, char *file){
    Team teams;
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return FALSE;

    char line[MAX_LINE_LENGTH];
    int found = FALSE;

    while(fgets(line, sizeof(line), fp) && !found){
      char *team_name = strtok(line, ",");

      if(strcmp(team_name, name) == 0){
        char *team_description = strtok(NULL, "\n");

        teams.team_name = team_name;
        teams.description = team_description;

        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("| EQUIPE: %s\n", teams.team_name);
        printf("| DESCRIÇÃO: %s\n", teams.description);
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

        found = TRUE;
      }
    }
    fclose(fp);
    return found;
}
