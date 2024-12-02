#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

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
    fprintf(fp,"}\n" );                                
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


int load_teams(const char *cpf,Team *teams){    // tanto para equipes academicas e empresariais 
    int found = FALSE;
    FILE *fp = fopen("data/teams.txt", "r");
    if (fp == NULL){
        show_error("Erro ao abrir o arquivo");
        return found;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp) != NULL){
        
        if(strstr(line, cpf) != NULL) {
            char *id_academic = strtok(NULL, ":");
            char *academy_especific = strtok(NULL, ":"); 
            if (academy_especific == NULL) continue;
            char *team_name_pos = strtok(NULL, ":");
            if (team_name_pos == NULL) continue;
            char *description = strtok(NULL, ":");

            teams->id = strdup(id_academic);
            teams->team_name_especific = strdup(academy_especific);
            teams->team_name = strdup(team_name_pos);
            teams->description = strdup(description);

            found = TRUE;
        }
    }
    fclose(fp);
    return found;
}

int update_date_teams(const char **id, const char *new_value, const char *field, int length){
    FILE *fp = fopen("data/teams.txt", "r+");
    if (fp == NULL) {
        show_error("Erro ao abrir o arquivo");
        return 0;
    }   
    char line[512];
    memset(line, 0, sizeof(line));
    long pos;
    int found_id = 0;

    while(fgets(line, sizeof(line), fp) != NULL){
        if (strstr(line, *id) != NULL) {
            found_id = 1;
        }

        if (found_id && strstr(line, field) != NULL ) {
            char *field_pos = strstr(line, field);
            if (field_pos == NULL) break;

            pos = ftell(fp) - strlen(line) + (field_pos - line) + strlen(field);
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%-*s", length, new_value);
            
            fclose(fp);
            return 1;
        }

           memset(line, 0, sizeof(line));
        }
         fclose(fp);
        return 0;
    }
   

