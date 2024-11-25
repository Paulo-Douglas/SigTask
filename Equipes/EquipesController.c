#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"

#include "EquipesController.h"
#include "EquipeModel.h"


int register_academic_team(void){
    Team teams;
    printf("Nome da equipe acadêmica: \n");
    teams.team_name = read_string();
    

    printf("Descrição da equipe acadêmica: \n");
    teams.description = read_description();

    int result = insert_to_teams(&teams, "data/academic_teams.txt");

    free(teams.team_name);
    free(teams.description);

    return result;

}


int register_business_team(void){
    Team teams;
    printf("Nome da equipe empresarial: \n");
    teams.team_name = read_string();
    

    printf("Descrição da equipe empresarial: \n");
    teams.description = read_description();

    int result = insert_to_teams(&teams, "data/business_teams.txt");

    free(teams.team_name);
    free(teams.description);

    return result;

}

int search_team(void) {
    int result = FALSE;
    printf("Nome da equipe a ser buscada:\n");
    char *name_team = read_string();

    char file;
    printf("Digite o tipo de equipe ( [1] EMPRESARIAL ou [2] ACADEMICA):\n");
    scanf(" %c", &file);
    getchar();
    limpar_tela();

    if (file == '1') {
        result = view_team(name_team, "data/business_teams.txt");
    } else if (file == '2') {
        result = view_team(name_team, "data/academic_teams.txt");
    }

    free(name_team);

    return result;

}
