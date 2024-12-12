#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

#include "EquipesController.h"
#include "EquipeModel.h"
#include "EquipesView.h"


int register_team(void){
    limpa_buffer();
    Team teams = {0};
    
    printf("|\tNome da equipe: ");
    char *name = read_string();
    strcpy(teams.name, name);

    printf("|\tDescrição da equipe: ");
    char *description = read_string();
    strcpy(teams.description, description);

    teams.status = '1';

    int result = insert_team(&teams);

    return result;
}
