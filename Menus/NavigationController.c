#include <stdio.h>
#include "Menus.h" 
#include "../Usuarios/UsuariosView.h"
#include "../Tarefas/TarefasView.h"
#include "../Compromissos/CompromissosView.h"

void navegacao_modulos(void) {
    char op;    
    do{
        op = menuPrincipal();
        switch (op){
            case '1':
                menu_usuarios();
                limpa_buffer();
                break;
            case '2':
                cadastrar_compromissos(); // colocar o de equipes aqui
                limpa_buffer();
                break;
            case '3':
                alterar_dados_tarefas(); // colocar o de agenda aqui
                limpa_buffer();
                break;
            case '4':
                menu_tarefas();
                limpa_buffer();
                break;
            case '5':
                menu_compromissos();
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