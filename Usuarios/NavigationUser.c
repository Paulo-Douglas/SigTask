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
            register_user();
            break;
        case '2':
            search_user();
            break;
        case '3':
            modify_user_data();
            break;
        case '4':
            delete_user();
            break;
        case '5':
            reactivate_user();
            break;
        case '6':
            show_users();
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