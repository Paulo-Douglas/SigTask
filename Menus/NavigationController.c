#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"
#include "../Equipes/EquipesView.h" // Mantendo a inclusão do módulo de equipes
#include "../libs/utils.h"
#include "../Usuarios/NavigationUser.h"
#include "../Compromissos/NavigationComp.h"
#include "../Compromissos/CompromissosView.h"
#include "../Equipes/EquipesView.h"
#include "../Equipes/NavigationTeams.h"

void navegacao_modulos(void) {
    char op;    
    do {
        op = menuPrincipal();
        switch (op) {
            case '1':
                navigation_users();
                break;
            case '2':
                navegacao_times();
                break;
            case '3':
                navigation_compromise();
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
