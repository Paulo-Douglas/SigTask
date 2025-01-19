#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

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

int insert_user(User *new_user)
{

    User *user_list = get_user_list();

    if (!user_list)
    {
        user_list = new_user;
    }
    else
    {

        User *current = user_list;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_user;
    }

    FILE *fp = fopen("data/users.dat", "wb");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo para salvar");
        free_user_list(user_list);
        return FALSE;
    }

    User *current = user_list;
    while (current != NULL)
    {
        if (fwrite(current, sizeof(User), 1, fp) != 1)
        {
            perror("Erro ao salvar usuário no arquivo");
            fclose(fp);
            free_user_list(user_list);
            return FALSE;
        }
        current = current->next;
    }

    fclose(fp);

    free_user_list(user_list);

    return TRUE;
}

User *get_user_list(void)
{
    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
        return NULL;

    User *first_user = NULL;
    User *current_user = NULL;

    while (1)
    {
        User *new_user = malloc(sizeof(User));
        if (new_user == NULL)
        {

            fclose(fp);
            free_user_list(first_user);
            return NULL;
        }

        if (fread(new_user, sizeof(User), 1, fp) != 1)
        {
            if (feof(fp))
            {

                free(new_user);
                break;
            }
            else
            {

                free(new_user);
                fclose(fp);
                free_user_list(first_user);

                return NULL;
            }
        }

        new_user->next = NULL;

        if (first_user == NULL)
        {
            first_user = new_user;
            current_user = first_user;
        }
        else
        {
            current_user->next = new_user;
            current_user = new_user;
        }
    }

    fclose(fp);
    return first_user;
}

void update_user_list(User *lista)
{
    FILE *fp = fopen("data/users.dat", "wb");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo para salvar");
        return;
    }

    User *current = lista;
    while (current != NULL)
    {
        if (fwrite(current, sizeof(User), 1, fp) != 1)
        {
            perror("Erro ao salvar usuário no arquivo");
            break;
        }
        current = current->next;
    }

    fclose(fp);
}

void free_user_list(User *lista)
{
    if (lista == NULL)
        return;
    User *temp;
    while (lista)
    {
        temp = lista;
        lista = lista->next;
        free(temp);
    }
}