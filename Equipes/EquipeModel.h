#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

typedef struct team Team;

struct team
{
    int id;
    char users[10][4];
    char name[50];
    char description[100];
    char status;
    Team *next;
};

typedef struct
{
    Team *start;
    int lenght;
} TeamList;

int generate_id_team(TeamList *list);
void create_list_team(TeamList *list);
void add_team_start(TeamList *list, Team *team);
void add_team_end(TeamList *list, Team *team);
void add_team_order(TeamList *list, Team *team);
void get_list_team(TeamList *list);
int save_team_list(TeamList *list);
void update_team_list(TeamList *list);
void free_team_list(TeamList *list);

#endif