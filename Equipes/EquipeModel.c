#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"



int insert_team_to_file(Team *teams){
  create_path("data/");
  FILE *fp = fopen("data/academic_teams.txt", "a");   

  int id = get_next_id("data/academic_teams.txt");
  if (id == 0) id = 1;
  
  if(fp == NULL) return FALSE;
  
    fprintf(fp, "%d:{", id);
    fprintf(fp, "%s%-*s,", FIELD_USER, VARCHAR50, "");    
    fprintf(fp, "%s%-*s,", FIELD_INSTITUICAO, VARCHAR50, teams->team_name_especific);       
    fprintf(fp, "%s%-*s,", FIELD_TEAM, VARCHAR50, teams->team_name);      
    fprintf(fp, "%s%-*s,", FIELD_DESCRIPTION, VARCHAR50, teams ->description);     
    fprintf(fp, "%s%s", FIELD_STATUS, teams->status); 
    fprintf(fp,"}\n" );                                
    fclose(fp);
    return TRUE;
}


int view_team(const char *id) {
    Team team;

    FILE *fp = fopen("data/academic_teams.txt", "r");
    if (fp == NULL) {
        return FALSE;
    };

    char line[500];
    int found = FALSE;

    while (fgets(line, sizeof(line), fp)) {
        char *id_team = strtok(line, ":");
        if (id[0] == *id_team){
            found = TRUE;
            team.id = id_team;

            char *field_user = strtok(NULL, ":");
            if(field_user == NULL) return FALSE;
            char *value_user = strtok(NULL, ",");

            char *field_inst = strtok(NULL, ":");
            if(field_inst == NULL) return FALSE;
            char *value_inst = strtok(NULL, ",");

            char *field_team = strtok(NULL, ":");
            if(field_team == NULL) return FALSE;
            char *value_team = strtok(NULL, ",");

            char *field_description = strtok(NULL, ":");
            if(field_description == NULL) return FALSE;
            char *value_description = strtok(NULL, ",");

            char *field_status = strtok(NULL, ":");
            if(field_status == NULL) return FALSE;
            char *value_status = strtok(NULL, "}");

            team.usuarios = value_user;
            team.team_name_especific = value_inst;
            team.team_name = value_team;
            team.description = value_description;
            team.status = value_status;

            team_data_academic(&team);

        }
    }

    fclose(fp);

    return found;
}


int update_date_teams(const char *id, const char *new_value, const char *field, int length){
    FILE *fp = fopen("data/academic_teams.txt", "r+");
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
