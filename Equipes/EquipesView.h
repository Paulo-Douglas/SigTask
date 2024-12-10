#ifndef EQUIPESVIEW_H
#define EQUIPESVIEW_H

#include "EquipeModel.h"

char menu_equipes(void);
void register_team_academic(void);
void search_team(void);
void excluir_equipe(void);
void add_user_to_team(void);
void remove_user_from_team(void);
void view_team(const Team *teams);
void modify_team_data_academic(void);


#endif