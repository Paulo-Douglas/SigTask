#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct user User;

struct user
{
    int id;
    char cpf[15];
    char name[100];
    char phone[14];
    char status;
    User *next;
};

typedef struct
{
    User *start;
    int lenght;
} UserList;

void create_list(UserList *list);
void add_user_start(UserList *list, User *user);
void add_user_end(UserList *list, User *user);
void add_user_order(UserList *list, User *user);

void update_user_list(User *lista);
int insert_user(User *users);
User *get_user_list(void);
void free_user_list(User *lista);

#endif // USUARIOSMODEL_H