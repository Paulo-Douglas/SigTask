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

int search_team(void) {
    char name_team[MAX_NAME_LENGTH];
    printf("Nome da equipe a ser buscada:\n");
    read_string(name_team);

    char file;
    printf("Digite o tipo de equipe ( [1] EMPRESARIAL ou [2] ACADEMICA):\n");
    scanf(" %c", &file);
    getchar();
    limpar_tela();

    if (file == '1') {
        return view_team(name_team, "data/business_teams.txt");
    } else if (file == '2') {
        return view_team(name_team, "data/academic_teams.txt");
    }
    return FALSE;
}