#include <stdio.h>

#include "NavigationTasks.h"
#include "TarefasView.h"

#include "../libs/utils.h"

void navigation_tasks(void){
    char op;
    do{
        op = tasks_menu();
        switch(op){
            case '1':  
                register_new_task();
                limpa_buffer();
                break;
            case '2':
                view_task();
                limpa_buffer();
                break;
            case '3':
                edit_task();
                limpa_buffer();
                break;
            case '4':
                delete_task();
                limpa_buffer();
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