#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int insert_user(void);
int upload_user_data(const char* cpf, User *users, const char **dir);
int update_user_data(User *users);

#endif // USUARIOSCONTROLLER_H