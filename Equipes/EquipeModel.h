#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

typedef struct team Team;

struct team
{
    char id[4];
    char users[10][4];
    char name[50];
    char description[100];
    char status;
    Team *next;
};

int get_id_team(void);
int insert_team(Team *teams);
Team *get_team_list(void);
void update_team_list(Team *list_team);
void free_team_list(Team *list_team);

#endif