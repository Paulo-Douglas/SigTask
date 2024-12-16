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
                edit_team();
                break;
            case '5':
                add_user_to_team();
                break;
            case '7':
                show_all_teams();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
    limpa_buffer();
    limpar_tela();
}
