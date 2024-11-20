#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct
{
    char *name;
    char *cpf;
    char *phone;
} User;

#define CPF_SIZE 14
#define NAME_SIZE 228
#define PHONE_SIZE 13
#define LINE_SIZE (CPF_SIZE + NAME_SIZE + PHONE_SIZE + 6)

int insert_to_user(User *users, const char* file_name);
// int udpate_user(User *users, const char* file_name);
int update_name_in_file(User *users, const char* file_name);
int update_phone_in_file(User *users, const char *file_name);
int select_all_user(const char *file_name);
int load_user(const char* cpf, User **users);

#endif // USUARIOSMODEL_H