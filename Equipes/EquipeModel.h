#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"


#define DESCRIPTION_SIZE 100
#define NAME_SIZE 228
#define LINE_TEAM (NAME_SIZE + DESCRIPTION_SIZE + 6)

typedef struct {
    char *id;
    char *usuarios;
    char *team_name_especific;
    char *team_name;
    char *description;
    char *status;
} Team;

int view_team(const char *id);
int insert_team_to_file(Team *teams);
int update_date_teams(const char *id, const char *new_value, const char *field, int length);
#endif