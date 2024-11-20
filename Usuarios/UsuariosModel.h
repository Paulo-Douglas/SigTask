#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct
{
    char *name;
    char *cpf;
    char *phone;
} User;

int insert_to_user(User *users, const char* file_name);
int load_user(const char *cpf);

#endif // USUARIOSMODEL_H