#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

typedef struct
{
  char team_name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
} Team;

int register_team(char *name, char *description);

#endif