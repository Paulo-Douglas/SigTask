#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct
{
    char cpf[15];
    char name[100];
    char phone[14];
    char status;
} User;

#define CPF_SIZE 14
#define NAME_SIZE 228
#define PHONE_SIZE 13
#define LINE_USER (CPF_SIZE + NAME_SIZE + PHONE_SIZE + 6)

int insert_user(User *users);
int update_user(User *new_data);
User* load_user(const char *cpf);

#endif // USUARIOSMODEL_H