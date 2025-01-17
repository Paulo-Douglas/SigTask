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
    create_path("data/");
    FILE *fp = fopen("data/users.dat", "ab");
    if (fp == NULL)
        return FALSE;

    int id = get_id_user();
    if (id == 0)
        id = 1;

    snprintf(new_user->id, sizeof(new_user->id), "%d", id);

    User *current_user = new_user;
    while (current_user != NULL)
    {
        fwrite(current_user, sizeof(User), 1, fp);
        current_user = current_user->next;
    }

    fclose(fp);
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
            // Libere os recursos antes de retornar
            fclose(fp);
            User *temp;
            while (first_user)
            {
                temp = first_user;
                first_user = first_user->next;
                free(temp);
            }
            return NULL;
        }

        // Leia os dados e verifique EOF
        if (fread(new_user, sizeof(User), 1, fp) != 1)
        {
            if (feof(fp))
            {
                // Final do arquivo alcançado com sucesso
                free(new_user); // Não adicionar o último malloc
                break;
            }
            else
            {
                // Erro durante a leitura
                free(new_user);
                fclose(fp);
                User *temp;
                while (first_user)
                {
                    temp = first_user;
                    first_user = first_user->next;
                    free(temp);
                }
                return NULL;
            }
        }

        new_user->next = NULL;

        // Construa a lista encadeada
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
