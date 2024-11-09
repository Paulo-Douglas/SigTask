#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"

#include "EquipeModel.h"

int register_team(char *name, char *description){
  Team teams;
  create_path("data");

  FILE *fp = fopen("data/teams.txt", "a");
  if (fp == NULL) return FALSE;

  strcpy(teams.team_name, name);
  strcpy(teams.description, description);

  fprintf(fp, "%s,%s", teams.team_name, teams.description);
  fclose(fp);
  return TRUE;
}

int view_team(char *name){
  Team teams;
  FILE *fp = fopen("data/temas.txt", "a");
  if (fp == NULL) return FALSE;

  char line[MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 5];
  int found = FALSE;

  while(fgets(line, sizeof(line), fp) && !found){
    char *team_name = strtok(line, ",");

    if(strcmp(team_name, name) == 0){
      char *team_description = strtok(NULL, "\n");

      strcpy(teams.team_name, team_name);
      strcpy(teams.description, team_description);

      printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
      printf("| EQUIPE: %s\n", teams.team_name);
      printf("| DESCRIÇÃO: %s\n", teams.description);
      printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    found = TRUE;
    }
  }

  return TRUE ? found : FALSE;

}