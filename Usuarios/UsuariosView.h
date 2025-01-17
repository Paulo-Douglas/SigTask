#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#include "UsuariosModel.h"

void user_menu_register(void);
void search_user(void);
void modify_user_data(void);
void delete_user(void);
void reactivate_user(void);
void show_users(void);
void display_data_user(const User *users);
char user_menu(void);
void diplay_users(User *lista);

User *initialize_user(const char status);

#endif