#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"


typedef struct {
    char id[4];
    char users[10][4];
    char name[50];
    char description[100];
    char status;
} Team;

void show_teams(void);

int insert_team(Team *teams);
int update_team(Team *new_team);
int get_id_team(void);
Team *load_team(const char *id);

#endif