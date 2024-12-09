#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

#include "EquipesController.h"
#include "EquipeModel.h"
#include "EquipesView.h"


int insert_team_academic(void){
    Team teams = {NULL, NULL, NULL, NULL,};
    
    read_and_assign(&teams.team_name_especific,"|\tNome da instituição: ", read_string);
    read_and_assign(&teams.team_name, "|\tNome da equipe: ", read_string);
    read_and_assign(&teams.description, "|\tDescrição: ", read_string);

    teams.status = "1";

    int result = insert_team_to_file(&teams); 

    return result;
}



int search_team(void) {
    int result = FALSE;
    char id;
    printf("ID da equipe a ser buscada:\n");
    scanf(" %c", &id);
    getchar();


    limpar_tela();

    result = view_team(&id);

    return result;

}

int update_team_academic(Team *teams, const char id){
    limpar_tela();
    
    char opc = '\0';
    int result = FALSE;

    do {
        printf("| Escolha uma opção para alterar: (1) Nome da instituição, (2) Nome da equipe, (3) Descrição, (0) Sair: \n");
        opc = getchar();
        getchar();
        switch (opc) {
            case '1':
                printf("|\tNome da instituição: ");
                teams->team_name_especific = read_string();
                result = update_date_teams(teams->id, teams->team_name_especific, FIELD_INSTITUICAO, VARCHAR50);
                result ? show_sucess("Nome da instituição alterado com sucesso!") : show_error("Erro ao alterar nome!");
                
            case '2':
                printf("|\tNome da equipe: ");
                teams->team_name = read_string();
                result = update_date_teams(teams->id, teams->team_name, FIELD_NAME, VARCHAR50);
                result ? show_sucess("Nome alterado com sucesso!") : show_error("Erro ao alterar nome!");

            case '3':
                printf("|\tDescrição: ");
                teams->description = read_description();
                result = update_date_teams(teams->id, teams->description, FIELD_DESCRIPTION, VARCHAR50);
                result ? show_sucess("Descrição alterada com sucesso!") : show_error("Erro ao alterar descrição!");

            case '0':
                return TRUE;

            default:
                printf("Opção inválida. Tente novamente.\n");
                return FALSE;
        }
    } while (opc != '0');

    return result;
}
