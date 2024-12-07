#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"



int insert_team_to_file(Team *teams){
  create_path("data/");
  FILE *fp = fopen("data/teams.txt", "a");   

  int id = get_next_id("data/teams.txt");
  
  if(fp == NULL) return FALSE;
  
    fprintf(fp, "%d:{", id);
    fprintf(fp, "%s %-*s", FIELD_USER, VARCHAR250, "");    
    fprintf(fp, "%s %-*s", FIELD_INSTITUICAO, VARCHAR50, teams->team_name_especific);       
    fprintf(fp, "%s %-*s", FIELD_TEAM, VARCHAR50, teams->team_name);      
    fprintf(fp, "%s %-*s", FIELD_DESCRIPTION, VARCHAR50, teams ->description);     
    fprintf(fp, "%s%s", FIELD_STATUS, teams->status); 
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


Team load_teams_academic(const char *id){    // tanto para equipes academicas e empresariais 
    Team teams;
    FILE *fp = fopen("data/teams.txt", "r");
    if (fp == NULL) exit(1);
       

    char line[512];
    while (fgets(line, sizeof(line), fp) != NULL){
        
        if (strcmp("NULL", id) == 0 || strstr(line, id) != NULL) {
            char *id_academic = strtok(NULL, ":");
            char *academy_especific = strtok(NULL, ":");    
            if (academy_especific == NULL) continue;
            char *team_name_pos = strtok(NULL, ":");
            if (team_name_pos == NULL) continue;
            char *description_pos = strtok(NULL, ":");
            if (description_pos == NULL) continue;
            char *description_value = strtok(NULL, ",");
            char *status_pos = strtok(NULL, ":");
            if (status_pos == NULL) continue;
            char *status_value = strtok(NULL, "}");


        
            

            teams.id = strdup(id_academic);
            teams.team_name_especific = strdup(academy_especific);
            teams.team_name = strdup(team_name_pos);
            teams.description = strdup(description_value);
            teams.status = strdup(status_value);
            team_data_academic(&teams);
            

        }
    }
    fclose(fp);
    return teams;
}

Team load_teams_business(const char *id){    // tanto para equipes academicas e empresariais 
    Team teams;
    FILE *fp = fopen("data/teams.txt", "r");
    if (fp == NULL) exit(1);
       

    char line[512];
    while (fgets(line, sizeof(line), fp) != NULL){
        
        if (strcmp("NULL", id) == 0 || strstr(line, id) != NULL) {
            char *id_academic = strtok(NULL, ":");
            char *academy_especific = strtok(NULL, ":");    
            if (academy_especific == NULL) continue;
            char *team_name_pos = strtok(NULL, ":");
            if (team_name_pos == NULL) continue;
            char *description_pos = strtok(NULL, ":");
            if (description_pos == NULL) continue;
            char *description_value = strtok(NULL, ",");
            char *status_pos = strtok(NULL, ":");
            if (status_pos == NULL) continue;
            char *status_value = strtok(NULL, "}");


        
            

            teams.id = strdup(id_academic);
            teams.team_name_especific = strdup(academy_especific);
            teams.team_name = strdup(team_name_pos);
            teams.description = strdup(description_value);
            teams.status = strdup(status_value);
            team_data_business(&teams);

        }
    }
    fclose(fp);
    return teams;
}

int update_date_teams(const char *id, const char *new_value, const char *field, int length){
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
        if (strstr(line, id) != NULL) {
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
   

