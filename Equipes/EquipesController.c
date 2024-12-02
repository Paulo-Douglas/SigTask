#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

#include "EquipesController.h"
#include "EquipeModel.h"
#include "EquipesView.h"


int register_academic_team(void){
    Team teams;
    printf("Nome da instituição");
    teams.team_name_especific = read_string();

    printf("Nome da equipe acadêmica: \n");
    teams.team_name = read_string();
    

    printf("Descrição da equipe acadêmica: \n");
    teams.description = read_description();

    int result = insert_to_teams(&teams, "data/academic_teams.txt");

    free_struct_teams(&teams);

    return result;

}


int register_business_team(void){
    Team teams;
    printf("Nome da empresa: \n");
    teams.team_name_especific = read_string();

    printf("Nome da equipe empresarial: \n");
    teams.team_name = read_string();
    

    printf("Descrição da equipe empresarial: \n");
    teams.description = read_description();

    int result = insert_to_teams(&teams, "data/business_teams.txt");

    free_struct_teams(&teams);

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

int update_team(Team *teams, const char *id){
    limpar_tela();
    char op;
    char opc;
    int result = FALSE;
    alterar_tipo_de_equipe();
    scanf(" %c", &op);
    if (op == '1') {
    do {
        limpar_tela();
        change_data_teams_academic();
        scanf(" %c", &opc);

        switch (opc) {
            case '1':
                limpa_buffer();
                printf("|\tNome da instituição: ");
                teams->team_name_especific = read_string();
                result = update_date_teams(&id, teams->team_name_especific, FIELD_NAME, VARCHAR50);
                
            case '2':
                limpa_buffer();
                printf("|\tNome da equipe: ");
                teams->team_name = read_string();
                result = update_date_teams(&id, teams->team_name, FIELD_NAME, VARCHAR50);
                

            case '3':
                limpa_buffer();
                printf("|\tDescrição: ");
                teams->description = read_description();
                result = update_date_teams(&id, teams->description, FIELD_DESCRIPTION, VARCHAR50);

            case '0':
                return TRUE;

            default:
                printf("Opção inválida. Tente novamente.\n");
                return FALSE;
        }
    } while (opc != '0');
}

    else if (op == '2'){
        do {
            limpar_tela();
            change_data_teams_business();
            scanf(" %c", &opc);

            switch(opc) {
                case '1':
                    limpa_buffer();
                    printf("|\tNome da empresa: "); 
                    teams->team_name_especific = read_string();
                    return update_date_teams(&id, teams->team_name_especific, FIELD_NAME, VARCHAR50);
                case '2':
                    limpa_buffer();
                    printf("|\tNome da equipe: ");
                    teams-> team_name = read_string();
                    return update_date_teams (&id, teams->team_name, FIELD_NAME, VARCHAR50);
                case '3':
                    limpa_buffer();
                    printf("|\tDescrição: ");
                    teams ->description = read_description();
                    return update_date_teams(&id, teams->description, FIELD_DESCRIPTION, VARCHAR50);
                          

        }
    } while (opc != '0');
     

}
    return result;
}   

void free_struct_teams(Team *teams) {
    if (teams->id != NULL) free(teams->id);
    if (teams->team_name_especific != NULL) free(teams->team_name_especific);
    if (teams->team_name != NULL) free(teams->team_name);
    if (teams->description != NULL) free(teams->description);
}