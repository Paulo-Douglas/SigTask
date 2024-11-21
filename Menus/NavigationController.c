#include <stdio.h>
#include <stdlib.h>
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
                break;
            case '2':
                navegacao_times();
                break;
            case '3':
                navegacao_tarefas();
                break;
            case '4':
                navegação_compromissos();
                break;
            case '5':
                menuSobre();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                limpa_buffer();
                break;
        }

    } while (op != '0');
}
