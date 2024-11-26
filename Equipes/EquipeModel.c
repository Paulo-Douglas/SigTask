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
  int id = get_next_id("data/teams.txt");
  create_path("data/");
  FILE *fp = fopen(file_teams, "a");    
  
  if(fp == NULL) return FALSE;
  
    fprintf(fp, "%d:{", id);  // id ou CNPJ
    fprintf(fp, "%s %-*s", FIELD_NAME, VARCHAR50, teams->team_name_especific);       
    fprintf(fp, "%s %-*s", FIELD_NAME, VARCHAR50, teams->team_name);      
    fprintf(fp, "%s %-*s", FIELD_DESCRIPTION, VARCHAR50, teams ->description);      
    fprintf(fp,"%s %-*s" );                                
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


int load_teams(Team *teams, const char *id, const char *mod){    // tanto para equipes academicas e empresariais 
    FILE *fp = fopen("data/teams.txt", "r");
    if (fp == NULL)
        return FALSE;
    char line[LINE_TEAM];
    int found = FALSE;
    int line_number = 0;

    while (fgets(line, LINE_TEAM, fp) != NULL){
        char *id_line = strtok(line, ",");
        if(strcmp(id, id_line) == 0) {
            char *id_academic = strtok(NULL, ":");
            delete_spaces(id_academic);
            char *academy_especific = strtok(NULL, ":"); 
            delete_spaces(academy_especific);
            char *name_team = strtok(NULL, ":");
            delete_spaces(name_team);
            char *description = strtok(NULL, ":");

            teams->id = strdup(id_academic);
            teams->team_name_especific = strdup(academy_especific);
            teams->team_name = strdup(name_team);
            teams->description = strdup(description);

            line_number++;
            getchar();
            found = TRUE;
        }
    }
    fclose(fp);
    return found;
}

int update_date_teams(const char delimit, const char *new_data, const int lenght, int id){
    FILE *fp = fopen("data/teams.txt", "r+");
    if (fp == NULL) {
        return FALSE;
    }   
    char line[LINE_TEAM];
    long pos;
    int found = FALSE;

    while(fgets(line, LINE_TEAM, fp) != NULL){
        if (strcmp(line, strtok(line, ",")) == 0){
            char *pos_strtok = strtok(NULL, "\n");
            pos = ftell(fp) - strlen(pos_strtok);

            char *pos_data = strchr(pos_strtok, delimit);
            if(pos_data != NULL){
                long data_pos = pos + (pos_data - pos_strtok);

                fseek(fp, data_pos, SEEK_SET);
                fprintf(fp, "%-*s", lenght, new_data);
                fflush(fp);
                found = TRUE;
            }

            break;
        }
    }
    fclose(fp);
    return found;
}
