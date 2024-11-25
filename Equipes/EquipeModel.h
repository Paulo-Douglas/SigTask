#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

#define NAME_SIZE 50
#define DESCRIPTION_SIZE 100
#define LINE_TEAM (NAME_SIZE + DESCRIPTION_SIZE + 6)

typedef struct {
    char *team_name;
    char *description;
} Team;

int view_team(char *name, char *file);
int insert_to_teams(Team *teams, const char* file_teams);
int update_name_in_teams(Team *teams, const char* file_teams);
int update_description_in_teams(Team *teams, const char* file_teams);
int update_status_in_teams(Team *teams, const char* file_teams);

#endif