#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct user User;

struct user
{
    char id[4];
    char cpf[15];
    char name[100];
    char phone[14];
    char status;
    User *next;
};

void report_users(const char condition);
int insert_user(User *users);
int update_user(User *new_data);
User *load_user(const char *cpf);
User *get_user_lit(void);

#endif // USUARIOSMODEL_H