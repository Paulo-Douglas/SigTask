#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct
{
    char *name;
    char *cpf;
    char *phone;
    char *status;
} User;

#define CPF_SIZE 14
#define NAME_SIZE 228
#define PHONE_SIZE 13
#define LINE_USER (CPF_SIZE + NAME_SIZE + PHONE_SIZE + 6)

int insert_user_to_file(User *users);
int update_data_user(const char *cpf, const char *new_value, const char *field, int length);
User load_user(const char *cpf);

#endif // USUARIOSMODEL_H