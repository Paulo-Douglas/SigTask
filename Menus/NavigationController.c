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
                break;
            case '2':
                cadastrar_compromissos(); // colocar o de equipes aqui
                break;
            case '3':
                alterar_dados_tarefas(); // colocar o de agenda aqui
                break;
            case '4':
                menu_tarefas();
                break;
            case '5':
                menu_compromissos();
                break;
            case '6':
                menuSobre();
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor ");
                break;
        }
      
    } while (op != '0');
}


