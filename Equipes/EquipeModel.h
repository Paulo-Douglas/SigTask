#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"


typedef struct {
    char *id;
    char *usuarios;
    char *team_name_especific;
    char *team_name;
    char *description;
    char *status;
} Team;

int insert_team_to_file(Team *teams);
#endif