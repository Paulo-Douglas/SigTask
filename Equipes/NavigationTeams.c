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
                register_team_academic();
                break;
            case '2':
                search_team();
                break;
            case '3':
                add_user_to_team();
                break;
            case '4':
                remove_user_from_team();
                break;
            case '5':
                excluir_equipe();
                break;
            case '6':
                modify_team_data_academic();
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
