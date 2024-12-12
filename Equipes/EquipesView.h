#ifndef EQUIPESVIEW_H
#define EQUIPESVIEW_H

#include "EquipeModel.h"

char menu_equipes(void);
void add_team(void);
void search_team(void);
void delete_team(void);
void view_team(const Team *teams);
void edit_team(void);


#endif