#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"

#include "EquipesController.h"
#include "EquipeModel.h"


int register_academic_team(void){
    printf("Nome da equipe acadêmica: \n");
    char *name_team = read_string();
    

    printf("Descrição da equipe acadêmica: \n");
    char *description = read_description();


    const char *data[3];
    data[0] = name_team;
    data[1] = description;
    data[2] = NULL;

    int result = save_file(data, "data/academic_teams.txt");

    free(name_team);
    free(description);

    return result;

}

int register_business_team(void){
    printf("Nome da equipe empresarial: \n");
    char *name_team = read_string();

    printf("Descrição da equipe empresarial: \n");
    char *description = read_description();

    const char *data[3];
    data[0] = name_team;
    data[1] = description;
    data[2] = NULL;

    int result = save_file(data, "data/academic_teams.txt");

    free(name_team);
    free(description);

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
