#include <stdio.h>
#include "NavigationTasks.h"
#include "TarefasView.h"
#include "../libs/utils.h"

void navegacao_tarefas(void){
    char op;
    do{
        op = menu_tarefas();
        switch(op){
            case '1':  
                cadastrar_tarefas();
                break;
            case '2':
                exibir_tarefas();
                break;
            case '3':
                alterar_dados_tarefas();
                break;
            case '4':
                excluir_tarefas();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
}   