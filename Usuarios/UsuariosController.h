#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

#include "UsuariosModel.h"

int register_user(void);
int search_user(const char* cpf);
int upload_data_user(const char* cpf, User *users);

#endif // USUARIOSCONTROLLER_H