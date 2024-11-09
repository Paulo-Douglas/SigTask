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