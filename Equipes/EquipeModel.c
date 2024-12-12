#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"



int insert_team_to_file(Team *teams){
    create_path("data/");
    FILE *fp = fopen("data/academic_teams.txt", "a");   

    fclose(fp);
    return TRUE;
}
