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
            menu_task_register();
            limpa_buffer();
            break;
        case '2':
            menu_task_search();
            limpa_buffer();
            break;
        case '3':
            menu_task_edit();
            limpa_buffer();
            break;
        case '4':
            menu_task_reports();
            limpa_buffer();
            break;
        case '0':
            break;
        default:
            show_error("Opção inválida, por favor, digite outro número.");
            enter();
            limpa_buffer();
            break;
        }
    } while (op != '0');
    limpa_buffer();
    limpar_tela();
}