#ifndef EQUIPESCONTROLLER_H
#define EQUIPESCONTROLLER_H

#include "EquipeModel.h"

int create_team(void);
int edit_team(const int id);
void show_all_teams(TeamList *team_list);
int teams_by_status(TeamList *team_list, const char status);
int team_by_user(TeamList *team_list, const int key);
int search_id_team(TeamList *team_list, const int id);
int modify_user_in_team(const int id, const int key);
void change_team_status(TeamList *team_list, const int id);

#endif