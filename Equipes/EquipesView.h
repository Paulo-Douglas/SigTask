#ifndef EQUIPESVIEW_H
#define EQUIPESVIEW_H

#include "EquipeModel.h"

char menu_equipes(void);
void add_team(void);
void search_team(void);
void delete_team(void);
void edit_team(void);
void add_user_to_team(void);
void display_data_team(const Team *teams);
void show_all_teams(void);


#endif