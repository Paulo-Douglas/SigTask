#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int create_user(void);
int edit_user(const int id);

void change_name(User *user);
void change_phone(User *user);
void show_all_users(UserList *list);
void users_by_status(UserList *list, const char status);
int search_id_user(User *list, const int id);
void change_status_user(UserList *list, const int id);

#endif // USUARIOSCONTROLLER_H