#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#include "UsuariosModel.h"

char menu_usuarios(void);
void cadastrar_usuarios(void);
void exibir_dados_usuario(void);
void alterar_dados_usuario(void);
void excluir_usuario(void);
void dados_usuario(User *users);


#endif