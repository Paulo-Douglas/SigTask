#include "Menus/Menus.h"
#include "Usuarios/UsuariosView.h"
#include "Tarefas/TarefasView.h"
#include "Compromissos/CompromissosView.h"

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
    menu_compromissos();
    cadastrar_compromissos();
    exibir_compromissos();
    editar_compromissos();
    excluir_compromissos();
    dados_compromissos();
    alterar_dados_compromissos();
    menuSobre();
    return 0;
}