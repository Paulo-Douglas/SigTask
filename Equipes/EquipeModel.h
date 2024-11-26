#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

#define FIELD_NAME "\"Nome\":" // lenght = 54
#define FIELD_PHONE "\"Telefone\":" // lenght = 1
#define FIELD_TITLE "\"Titulo\":" // lenght = 54
#define FIELD_DESCRIPTION "\"Descricao\":" // lenght = 54
#define FIELD_DATE "\"Data\":" // lenght = 1
#define FIELD_PRIORITY "\"Prioridade\":" // 0 = Baixa, 1 = Media, 2 = Alta || length = 1
#define FIELD_STATUS "\"Status\":" // 0 = Aberto, 1 = Em andamento, 2 = Fechado || 0 = Inativo 1 = Ativo || length = 1

#define VARCHAR50 50
#define DESCRIPTION_SIZE 100
#define NAME_SIZE 228
#define LINE_TEAM (NAME_SIZE + DESCRIPTION_SIZE + 6)

typedef struct {
    char *id;
    char *team_name_especific;
    char *team_name;
    char *description;
} Team;

int view_team(char *name, char *file);
int insert_to_teams(Team *teams, const char* file_teams);
int update_name_in_teams(Team *teams, const char* file_teams);
int update_description_in_teams(Team *teams, const char* file_teams);
int update_status_in_teams(Team *teams, const char* file_teams);
int load_teams(Team *teams, const char *id, const char *mod);
int update_date_teams(const char delimit, const char *new_data, const int lenght, int id);
#endif