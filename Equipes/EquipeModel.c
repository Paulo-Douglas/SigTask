#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"

#include "EquipeModel.h"



/*
  %s:%-100s#%c\n
  1-> Tamanho do arquivo + 1
  2-> Tamaho da descrição
  3-> 1 para ativo / 0 para inativo
*/

int insert_to_teams(Team *teams, const char* file_teams){
  int id = lenght_line(file_teams);
  create_path("data/");
  FILE *fp = fopen(file_teams, "a");    
  
  if(fp == NULL) return FALSE;
  
    fprintf(fp, "%d:%-50s;%-100s#1\n", id, teams->team_name, teams->description);
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

int update_name_in_teams(Team *teams, const char* file_teams){
  FILE *fp = fopen(file_teams, "r+");
  if (fp == NULL) return FALSE;

  char line[LINE_SIZE];
  long pos; 
  int found = FALSE;

  while (fgets(line, LINE_SIZE, fp) != NULL){
    if (strstr(line, teams -> team_name) != NULL){
      pos = ftell(fp) - strlen(line);

      char *delimiter_pos = strchr(line, ':');
      if (delimiter_pos != NULL){
        long name_pos = pos + (delimiter_pos - line) + 1;

        fseek(fp, name_pos, SEEK_SET);
        fprintf(fp, "%-50s", teams->team_name);
        fflush(fp);
        found = TRUE;
      }

        break;
      }

    }
    return found;
}

int update_description_in_teams(Team *teams, const char* file_teams){
  FILE *fp = fopen(file_teams, "+r");
  if (fp == NULL) return FALSE;

  char line[LINE_SIZE];
  long pos;
  int found = FALSE;

  while(fgets(line, LINE_SIZE, fp) != NULL){
    if(strstr(line, teams -> description) != NULL){
      pos = ftell(fp) - strlen(line);

      char *delimiter_pos = strchr (line, ':');
      if (delimiter_pos != NULL){
        long name_pos = pos + (delimiter_pos - line) + 1;

        fseek(fp, name_pos, SEEK_SET);
        fprintf(fp, "%-30s", teams -> description);
        fflush(fp);
        found = TRUE;
      }
      break;
        }
  }
  return found;

}

int update_status_in_teams(Team *teams, const char* file_teams){
    FILE *fp = fopen(file_teams, "r+");
    if (fp == NULL) return FALSE;

    char line[LINE_SIZE];
    long pos;
    int found = FALSE;

    while (fgets(line, LINE_SIZE, fp) != NULL){
        if (strstr(line, teams->team_name) != NULL){
            pos = ftell(fp) - strlen(line);

            char *delimiter_pos = strchr(line, '#');

            long status_pos = pos + (delimiter_pos - line) + 1;

            char status_actual = *(delimiter_pos + 1);
            char new_status = (status_actual == '1') ? '0' : '1';

            fseek(fp, status_pos, SEEK_SET);
            fprintf(fp, "%c", new_status);
            fflush(fp);
            found = TRUE;
            break;
        }
    }
    fclose(fp);
    return found;
}