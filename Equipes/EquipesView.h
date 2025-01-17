#ifndef EQUIPESVIEW_H
#define EQUIPESVIEW_H

#include "EquipeModel.h"

char menu_team(void);
void menu_team_register(void);
void menu_search_team(void);
void menu_team_status(void);
void menu_team_edit(void);
void menu_team_user_edit(void);
void menu_team_display(const Team *teams);
void menu_team_report(void);
void feedback_team(Team *team, const char *error_message, const char *success_message);

#endif