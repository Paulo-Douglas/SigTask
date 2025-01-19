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

int generate_user_id(UserList *list);
void create_list(UserList *list);
void add_user_start(UserList *list, User *user);
void add_user_end(UserList *list, User *user);
void add_user_order(UserList *list, User *user);
void get_list_user(UserList *list);
int save_user_list(UserList *list);

void update_user_list(User *lista);
User *get_user_list(void);
void free_user_list(User *lista);

#endif // USUARIOSMODEL_H