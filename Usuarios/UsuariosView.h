#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#include "UsuariosModel.h"

char user_menu(void);
void register_user(void);
void display_user_data(void);
void modify_user_data(void);
void delete_user(void);
void user_data(User *users);
void reactivate_user(void);
User get_user_by_cpf(const char *mod);


#endif