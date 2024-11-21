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

/*
  %s:%-100s#%c\n
  1-> Tamanho do arquivo + 1
  2-> Tamaho da descrição
  3-> 1 para ativo / 0 para inativo
*/

int insert_to_teams(Team *teams, const char* file_teams){
  create_path("data/");
  FILE *fp = fopen(file_teams, "a");
  if(fp = NULL) return FALSE;
  
    fprintf(fp, "%c:%-50s;%-30s#1\n", teams->team_name, teams->description);
    fclose(fp);
    return TRUE;
}


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

