#ifndef USUARIOVIEW_H
#define USUARIOVIEW_H

#include "UsuariosModel.h"

char user_menu(void);
void user_menu_register(void);
void user_menu_search(void);
void user_menu_edit(void);
void user_menu_status(void);
void user_menu_reports(void);
void user_menu_display(const User *users);
void feedback_user(User *current_user, const char *error_message, const char *success_message);

#endif