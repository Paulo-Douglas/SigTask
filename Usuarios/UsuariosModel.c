#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

int generate_user_id(UserList *list)
{
    int max_id = 0;

    User *current = list->start;
    while (current != NULL)
    {
        if (current->id > max_id)
        {
            max_id = current->id;
        }
        current = current->next;
    }

    return max_id;
}

void create_list(UserList *list)
{
    list->start = NULL;
    list->lenght = 0;
}

void add_user_start(UserList *list, User *user)
{
    user->next = list->start;
    list->start = user;
    list->lenght++;
}

void add_user_end(UserList *list, User *user)
{
    if (list->start == NULL)
        add_user_start(list, user);
    else
    {
        User *aux = list->start;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = user;
    }
    list->lenght++;
}

void add_user_order(UserList *list, User *user)
{
    if (list->start == NULL || strcmp(list->start->name, user->name) > 0)
        add_user_start(list, user);
    else
    {
        User *aux = list->start;
        while (aux->next != NULL && strcmp(aux->next->name, user->name) < 0)
            aux = aux->next;
        user->next = aux->next;
        aux->next = user;
    }
    list->lenght++;
}

void get_list_user(UserList *list)
{
    FILE *fp = fopen("data/users.dat", "rb");
    if (!fp)
        return;

    while (!feof(fp))
    {
        User *novo_usuario = (User *)malloc(sizeof(User));
        if (fread(novo_usuario, sizeof(User), 1, fp) != 1)
        {
            free(novo_usuario);
            break;
        }
        novo_usuario->next = NULL;

        add_user_end(list, novo_usuario);
    }
    fclose(fp);
}

int save_user_list(UserList *list)
{
    create_path("data/");
    FILE *fp = fopen("data/users.dat", "wb");
    if (!fp)
        return FALSE;

    User *aux = list->start;
    while (aux != NULL)
    {
        fwrite(aux, sizeof(User), 1, fp);
        aux = aux->next;
    }
    fclose(fp);

    return TRUE;
}

void update_user_list(UserList *list)
{
    FILE *fp = fopen("data/users.dat", "wb");
    if (!fp)
        return;

    User *aux = list->start;
    while (aux != NULL)
    {
        fwrite(aux, sizeof(User), 1, fp);
        aux = aux->next;
    }
    fclose(fp);
}

void free_user_list(UserList *list)
{
    User *aux = list->start;
    while (aux != NULL)
    {
        User *next = aux->next;
        free(aux);
        aux = next;
    }
}