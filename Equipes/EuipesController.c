#include <stdio.h>

#include "../libs/utils.h"
#include "../libs/reads.h"

#include "EquipesController.h"
#include "EquipeModel.h"


void register_academic_team(void){
  char name_team[MAX_NAME_LENGTH];
  printf("Nome da equipe acadêmica: \n");
  read_string(name_team);

  char description[MAX_DESCRIPTION_LENGTH];
  printf("Descrição da equipe acadêmica: \n");
  read_description(description);

  register_team(name_team, description);

}

void register_business_team(void){
    char name_equipe[MAX_NAME_LENGTH];
    printf("Nome da equipe empresarial: \n");
    read_string(name_equipe);

    char description[MAX_DESCRIPTION_LENGTH];
    printf("Descrição da equipe empresarial: \n");
    read_description(description);
}