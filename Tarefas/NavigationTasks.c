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
                limpa_buffer();
                break;
            case '2':
                exibir_tarefas();
                limpa_buffer();
                break;
            case '3':
                editar_tarefas();
                limpa_buffer();
                break;
            case '4':
                excluir_tarefas();
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