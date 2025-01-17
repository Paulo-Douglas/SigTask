#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int create_user(void);
void edit_user(User *user);
void show_all_users(User *lista);
void users_by_status(User *lista, const char status);

#endif // USUARIOSCONTROLLER_H