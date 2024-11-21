#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

#define NAME_SIZE 50
#define DESCRIPTION_SIZE 100
#define LINE_SIZE (NAME_SIZE + DESCRIPTION_SIZE + 6)

int view_team(char *name, char *file);
int insert_to_teams(Team *teams, const char* file_teams);

#endif