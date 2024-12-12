#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"



int insert_team(Team *teams){
    int result = FALSE;

    create_path("data/");
    FILE *fp = fopen("data/academic_teams.dat", "ab");   
    if (fp == NULL) return result;

    int id = get_next_id("data/academic_teams.dat");
    if(id == 0) id = 1;

    snprintf(teams->id, sizeof(teams->id), "%d", id);


    if (fwrite(teams, sizeof(Team), 1, fp)) result = TRUE;

    fclose(fp);
    return TRUE;
}

Team *load_team(const char *id){
    FILE *fp = fopen("data/academic_teams.dat", "rb");
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
    FILE *fp = fopen("data/academic_teams.dat", "rb+");
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
