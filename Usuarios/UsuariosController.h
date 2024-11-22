#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int register_user(void);
int upload_data_user(const char* cpf, User *users, const char **dir);
int update_data_user(User *users);

#endif // USUARIOSCONTROLLER_H