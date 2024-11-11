#ifndef EQUIPEMODEL_H
#define EQUIPEMODEL_H

#include "../libs/utils.h"

typedef struct
{
  char team_name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
} Team;

typedef struct {
  char **file;
  int line_count;
} File;

int register_team(char *name, char *description, char *file);
int view_team(char *name, char *file);
int move_to_struct(File *read_file, char *equipe, char *cpf, char *name_team);
int add_user_to_register(File *read_file, char *equipe, char *cpf);

#endif