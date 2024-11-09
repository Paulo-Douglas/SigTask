#include <stdio.h>

#include "../libs/utils.h"
#include "../libs/reads.h"

#include "EquipesController.h"
#include "EquipeModel.h"


int register_academic_team(void){
  char name_team[MAX_NAME_LENGTH];
  printf("Nome da equipe acadêmica: \n");
  read_string(name_team);

  char description[MAX_DESCRIPTION_LENGTH];
  printf("Descrição da equipe acadêmica: \n");
  read_description(description);

  return register_team(name_team, description, "data/academic_teams.txt");

}

int register_business_team(void){
    char name_team[MAX_NAME_LENGTH];
    printf("Nome da equipe empresarial: \n");
    read_string(name_team);

    char description[MAX_DESCRIPTION_LENGTH];
    printf("Descrição da equipe empresarial: \n");
    read_description(description);

  return register_team(name_team, description, "data/business_teams.txt");

}