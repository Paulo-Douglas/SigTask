#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"


typedef struct {
    char id[4];
    char users[10];
    char name[50];
    char description[100];
    char status;
} Team;

int insert_team(Team *teams);
int update_team(Team *new_team);
int get_id_user(void);
Team *load_team(const char *id);

#endif