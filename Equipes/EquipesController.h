#ifndef EQUIPESCONTROLLER_H
#define EQUIPESCONTROLLER_H

#include "EquipeModel.h"

int register_academic_team(void);
int register_business_team(void);
int search_team(void);
int update_team(Team *teams, char *id);

#endif