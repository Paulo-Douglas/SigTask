#include "Menus/Menus.h"
#include "Usuarios/UsuariosView.h"

int main(void) {
    menuPrincipal();
    menu_usuarios();
    cadastrar_usuarios();
    exibir_dados();
    alterar_dados();
    excluir_usuario();
    menuSobre();
    return 0;
}