#ifndef EQUIPESCONTROLLER_H
#define EQUIPESCONTROLLER_H

#include "EquipeModel.h"

int create_team(void);
void edit_team(Team *team_list, const char id[4]);
void show_all_teams(Team *team_list);
void teams_by_status(Team *team_list, const char status);
void team_by_user(Team *team_list, const char *key);
int search_id_team(Team *team_list, const char *id);
void add_user_to_team(Team *team_list, const char id[4]);
void change_team_status(Team *team_list, const char id[4]);

#endif