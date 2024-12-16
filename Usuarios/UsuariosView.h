#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#include "UsuariosModel.h"

void register_user(void);
void search_user(void);
void modify_user_data(void);
void delete_user(void);
void user_data(const User *users);
void reactivate_user(void);
char user_menu(void);


#endif