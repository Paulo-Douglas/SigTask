#include <stdio.h>
#include "NavigationTeams.h"
#include "EquipesView.h"
#include "../libs/utils.h"

void navegacao_times(void){
    char op;
    do{
        op = menu_equipes();
        switch(op){
            case '1':  
                add_team();
                break;
            case '2':
                search_team();
                break;
            case '3':
                delete_team();
                break;
            case '4':
                reactive_team();
                break;
            case '5':
                edit_team();
                break;
            case '6':
                edit_team_user();
                break;
            case '7':
                show_teams();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
    limpar_tela();
}
