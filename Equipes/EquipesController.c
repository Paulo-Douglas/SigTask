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

void modify_team_data(Team *team){
    char op;
    int result = FALSE;

    do {
        printf("|\t[1] Editar nome\n");
        printf("|\t[2] Editar descrição\n");
        printf("|\t[0] Sair\n");
        scanf(" %c", &op);

        switch (op){
            case '1':
                limpa_buffer();
                printf("|\tNome: ");
                char *name = read_string();
                strcpy(team->name, name);
                result = update_team(team);
                result ? show_sucess("Nome editado com sucesso!") : show_error ("Erro ao editar o nome");
                break;
            case '2':
                limpa_buffer();
                printf("|\tDescrição: ");
                char *description = read_string();
                strcpy(team->description, description);
                result = update_team(team);
                result ? show_sucess("Descrição editada com sucesso!") : show_error ("Erro ao editar a descrição");
                break;
            case '0':
                break;
            default:
                show_error("Opção inválida.");
                break;
        }
    } while (op != '0');
}
