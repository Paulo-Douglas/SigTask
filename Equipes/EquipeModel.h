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

void report_teams(const char condition, const char *key);
void remove_user_inactive_teams(const char id[4]);

int insert_team(Team *teams);
int update_team(Team *new_team);
int get_id_team(void);
Team *load_team(const char *id);

#endif