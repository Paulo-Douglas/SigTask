#include "Menus/Menus.h"
#include "Usuarios/UsuariosView.h"

int main(void) {
    menuPrincipal();
    menu_usuarios();
    cadastrar_usuarios();
    exibir_dados_usuario();
    alterar_dados_usuario();
    excluir_usuario();
    menuSobre();
    return 0;
}