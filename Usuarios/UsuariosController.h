#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int create_user(void);
void edit_user(User *user, const char id[4]);
void change_name(User *user);
void change_phone(User *user);
void show_all_users(User *lista);
void users_by_status(User *lista, const char status);
int search_id_user(User *lista, const char *id);
void change_status_user(User *user, const char *id);

#endif // USUARIOSCONTROLLER_H