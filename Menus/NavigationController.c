#include <stdio.h>
#include "Menus.h"
#include "../Equipes/EquipesView.h" // Mantendo a inclusão do módulo de equipes
#include "../libs/utils.h"
#include "../Usuarios/NavigationUser.h"
#include "../Compromissos/NavigationComp.h"
#include "../Tarefas/NavigationTasks.h"
#include "../Compromissos/CompromissosView.h"
#include "../Equipes/EquipesView.h"
#include "../Equipes/NavigationTeams.h"

void navegacao_modulos(void) {
    char op;    
    do {
        op = menuPrincipal();
        switch (op) {
            case '1':
                navegacao_usuarios();
                limpa_buffer();
                break;
            case '2':
                navegacao_times(); // ou use menu_equipes(), dependendo da função que quer chamar
                limpa_buffer();
                break;
            case '3':
                editar_equipe(); // colocar o de agenda aqui
                limpa_buffer();
                break;
            case '4':
                navegacao_tarefas();
                limpa_buffer();
                break;
            case '5':
                navegação_compromissos();
                limpa_buffer();
                break;
            case '6':
                menuSobre();
                limpa_buffer();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
      
    } while (op != '0');
}
