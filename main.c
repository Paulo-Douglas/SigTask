#include "Menus/Menus.h"
#include "Usuarios/UsuariosView.h"
#include "Tarefas/TarefasView.h"

int main(void) {
    menuPrincipal();
    menu_usuarios();
    cadastrar_usuarios();
    exibir_dados_usuario();
    alterar_dados_usuario();
    excluir_usuario();
    menu_tarefas();
    cadastrar_tarefas();
    exibir_tarefas();
    editar_tarefas();
    excluir_tarefas();
    dados_tarefas();
    alterar_dados_tarefas();
    menuSobre();
    return 0;
}