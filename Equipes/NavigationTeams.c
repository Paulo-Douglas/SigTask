#include <stdio.h>
#include "NavigationTeams.h"
#include "EquipesView.h"
#include "../libs/utils.h"

void navegacao_times(void)
{
    char op;
    do
    {
        op = menu_team();
        switch (op)
        {
        case '1':
            menu_team_register();
            break;
        case '2':
            menu_search_team();
            break;
        case '3':
            menu_team_status();
            break;
        case '4':
            menu_team_edit();
            break;
        case '5':
            menu_team_user_edit();
            break;
        case '6':
            menu_team_report();
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
