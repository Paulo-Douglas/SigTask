#ifndef EQUIPESCONTROLLER_H
#define EQUIPESCONTROLLER_H

#include "EquipeModel.h"

int insert_team_business(void);
int insert_team_academic(void);
int search_team(void);
int update_team_academic(Team *teams);
void free_struct_teams(Team *teams);
int update_team_business(Team *teams);

#endif