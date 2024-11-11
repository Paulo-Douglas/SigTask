#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"

#include "EquipeModel.h"

int register_team(char *name, char *description, char *file){
  create_path("data");

  FILE *fp = fopen(file, "a");
  if (fp == NULL) return FALSE;

  fputs(name, fp);
  fputc(',', fp);
  fputs(description, fp);
  fputc('\n', fp);

  fclose(fp);
  return TRUE;
}

int view_team(char *name, char *file){
  Team teams;
  FILE *fp = fopen(file, "r");
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
  fclose(fp);
  return found;
}

int move_to_struct(File *read_file, char *equipe, char *cpf) {
    read_file->file = NULL;
    read_file->line_count = 0;

    char line[MAX_LINE_LENGTH];

    FILE * fp = fopen("teams.txt", "r");    
    if (fp == NULL) return FALSE;

    while(fgets(line, MAX_LINE_LENGTH, fp) !=NULL) {
        read_file->line_count++;
        read_file->file = realloc(read_file->file, read_file->line_count * sizeof(char *));

        if (read_file->file == NULL){
            fclose(fp);
            return FALSE;
        }

        read_file->file[read_file->line_count - 1] = malloc(strlen(line) + 1);

        if (read_file->file[read_file->line_count - 1] == NULL){
            fclose(fp);
            return FALSE;
        }

        strcpy(read_file->file[read_file->line_count - 1], line);

    }

    add_user_to_file(read_file, equipe, cpf);
    fclose(fp);
    free(read_file->file);
    return TRUE;

}