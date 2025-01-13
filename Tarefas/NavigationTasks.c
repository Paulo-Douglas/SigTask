#include <stdio.h>

#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/styles.h"

void navigation_tasks(void)
{
    char op;
    do
    {
        op = menu_task();
        switch (op)
        {
        case '1':
            add_task();
            limpa_buffer();
            break;
        case '2':
            search_task();
            limpa_buffer();
            break;
        case '3':
            change_task();
            limpa_buffer();
            break;
        case '4':
            delete_task();
            limpa_buffer();
            break;
        case '5':
            show_all_tasks();
            limpa_buffer();
            break;
        case '0':
            break;
        default:
            show_error("Opção inválida, por favor, digite outro número.");
            limpa_buffer();
            break;
        }
    } while (op != '0');
    limpa_buffer();
    limpar_tela();
}