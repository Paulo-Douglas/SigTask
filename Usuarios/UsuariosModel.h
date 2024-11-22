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

int insert_user_to_file(User *users, const char* file_name);
// int udpate_user(User *users, const char* file_name);
int update_user_name(User *users, const char* file_name);
int update_user_phone(User *users, const char *file_name);
int update_user_status(User *users, const char *file_name, const char *dir);
int select_all_users(const char *file_name);
int load_user_from_users(const char* cpf, User **users, const char **dir);

#endif // USUARIOSMODEL_H