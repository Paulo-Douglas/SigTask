#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"


int get_id_team(void){
    FILE * fp = fopen("data/teams.dat", "rb");
    if (fp == NULL) return FALSE;

    Team last_team;
    int next_id = 1;

    fseek(fp, -sizeof(Team), SEEK_END);

    if (fread(&last_team, sizeof(Team), 1, fp)){
        next_id = atoi(last_team.id) + 1;
    }

    fclose(fp);
    return next_id;
}


int insert_team(Team *teams){
    int result = FALSE;

    create_path("data/");
    FILE *fp = fopen("data/teams.dat", "ab");   
    if (fp == NULL) return result;

    int id = get_id_team();

    snprintf(teams->id, sizeof(teams->id), "%d", id);

    if (fwrite(teams, sizeof(Team), 1, fp)) result = TRUE;

    fclose(fp);
    return TRUE;
}


Team *load_team(const char *id){
    FILE *fp = fopen("data/teams.dat", "rb");
    if(fp == NULL) return NULL;

    Team *team = (Team *)malloc(sizeof(Team));
    while(fread(team, sizeof(Team), 1, fp)){
        if(strcmp(team->id, id) == 0){
            fclose(fp);
            return team;
        }
    }
    fclose(fp);
    free(team);
    return NULL;
}


int update_team(Team *new_team){
    FILE *fp = fopen("data/teams.dat", "rb+");
    if(fp == NULL) return FALSE;

    Team team;
    while(fread(&team, sizeof(Team), 1, fp)){
        if(strcmp(team.id, new_team->id) == 0){
            fseek(fp, -sizeof(Team), SEEK_CUR);
            fwrite(new_team, sizeof(Team), 1, fp);
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}

void remove_user_inactive_teams(const char id[4]){
    FILE *fp = fopen("data/teams.dat", "rb+");
    if (fp == NULL) return;

    Team team;
    while (fread(&team, sizeof(Team), 1, fp) != EOF){
        for (int i = 0; i < 10; i++){
            if (strcmp(team.users[i], id) == 0){
                team.users[i][0] = '\0';
                update_team(&team);
            }
        }
    }
}

void report_teams(const char condition, const char *key){
    FILE *fp = fopen("data/teams.dat", "rb");
    if (fp == NULL) return; 

    Team team;
    while (fread(&team, sizeof(Team), 1, fp)){
        if (condition == '\0' && strcmp(key, "all") == 0) display_data_team(&team);
        else if (team.status == condition && strcmp(key, "status") == 0) display_data_team(&team);
    }

    getchar();
    fclose(fp);
}