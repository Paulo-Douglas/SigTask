#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosModel.h"
#include "UsuariosView.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

int get_id_user(void)
{
    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
        return FALSE;

    User last_user;
    int next_id = 1;

    fseek(fp, -sizeof(User), SEEK_END);

    if (fread(&last_user, sizeof(User), 1, fp))
    {
        next_id = atoi(last_user.id) + 1;
    }

    fclose(fp);
    return next_id;
}

int insert_user(User *new_user)
{
    User *first_user = NULL;
    User *last_user = NULL;

    FILE *fp = fopen("data/users.dat", "rb");
    if (fp != NULL)
    {
        User temp_user;
        while (fread(&temp_user, sizeof(User), 1, fp))
        {
            User *node = (User *)malloc(sizeof(User));
            if (!node)
            {
                fclose(fp);
                return FALSE;
            }
            *node = temp_user;
            node->next = NULL;

            if (first_user == NULL)
            {
                first_user = last_user = node;
            }
            else
            {
                last_user->next = node;
                last_user = node;
            }
        }
        fclose(fp);
    }

    if (first_user == NULL)
    {
        first_user = new_user;
    }
    else
    {
        last_user->next = new_user;
    }

    new_user->next = NULL;

    fp = fopen("data/users.dat", "wb");
    if (fp == NULL)
    {
        return FALSE;
    }

    User *current = first_user;
    while (current != NULL)
    {
        fwrite(current, sizeof(User), 1, fp);
        current = current->next;
    }

    fclose(fp);

    while (first_user != NULL)
    {
        User *temp = first_user;
        first_user = first_user->next;
        free(temp);
    }

    return TRUE;
}

int update_user(User *new_data)
{
    FILE *fp = fopen("data/users.dat", "rb+");
    if (fp == NULL)
        return FALSE;

    User user;
    while (fread(&user, sizeof(User), 1, fp))
    {
        if (strcmp(user.cpf, new_data->cpf) == 0)
        {
            fseek(fp, -sizeof(User), SEEK_CUR);
            fwrite(new_data, sizeof(User), 1, fp);
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}

User *load_user(const char *cpf)
{
    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
        return NULL;

    User *user = (User *)malloc(sizeof(User));
    while (fread(user, sizeof(User), 1, fp))
    {
        if (strcmp(user->cpf, cpf) == 0)
        {
            fclose(fp);
            return user;
        }
    }

    fclose(fp);
    free(user);
    return NULL;
}

void report_users(const char condition)
{
    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
        return;

    User user;
    while (fread(&user, sizeof(User), 1, fp))
    {
        if (condition == '\0')
        {
            display_data_user(&user);
        }
        else
        {
            if (user.status == condition)
            {
                display_data_user(&user);
            }
        }
    }

    getchar();
    fclose(fp);
}
