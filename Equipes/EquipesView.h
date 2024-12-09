#ifndef EQUIPESVIEW_H
#define EQUIPESVIEW_H

#include "EquipeModel.h"

char menu_equipes(void);
void cadastro_tipo_de_equipe(void);
void cadastrar_equipe_academica(void);
void cadastrar_equipe_empresarial(void);
void exibir_equipe(void);
void excluir_equipe(void);
void alterar_tipo_de_equipe(void);
void add_user_to_team(void);
void remove_user_from_team(void);
void team_data_academic(const Team *teams);
void modify_team_data_academic(void);
void team_data_business(const Team *teams);
void modify_team_data_business(void);


#endif