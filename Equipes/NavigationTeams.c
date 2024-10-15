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
                cadastro_tipo_de_equipe();
                break;
            case '2':
                exibir_equipe();
                break;
            case '3':
                editar_equipe();
                break;
            case '4':
                excluir_equipe();
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
}   