#include <stdio.h>

#include "NavigationUser.h"
#include "UsuariosView.h"

#include "../libs/utils.h"

void navigation_users(void)
{
    char op;
    do
    {
        op = user_menu();
        switch (op)
        {
        case '1':
            user_menu_register();
            break;
        case '2':
            user_menu_search();
            break;
        case '3':
            user_menu_edit();
            break;
        case '4':
            user_menu_status();
            break;
        case '5':
            user_menu_reports();
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