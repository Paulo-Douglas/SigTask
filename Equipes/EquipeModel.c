#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"

int get_id_team(void)
{
    FILE *fp = fopen("data/teams.dat", "rb");
    if (fp == NULL)
    {
        return FALSE;
    }

    Team last_team;
    int next_id = 1;

    fseek(fp, -sizeof(Team), SEEK_END);

    if (fread(&last_team, sizeof(Team), 1, fp))
    {
        next_id = atoi(last_team.id) + 1;
    }

    fclose(fp);
    return next_id;
}

int insert_team(Team *new_team)
{
    int id = get_id_team();
    if (id == 0)
        id = 1;

    snprintf(new_team->id, sizeof(new_team->id), "%d", id);

    Team *list_team = get_team_list();

    if (!list_team)
    {
        list_team = new_team;
    }
    else
    {
        Team *current = list_team;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_team;
    }

    FILE *fp = fopen("data/teams.dat", "wb");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo para salvar");
        free_team_list(list_team);
        return FALSE;
    }

    Team *current = list_team;
    while (current != NULL)
    {
        if (fwrite(current, sizeof(Team), 1, fp) != 1)
        {
            perror("Erro ao salvar equipe no arquivo");
            fclose(fp);
            free_team_list(list_team);
            break;
        }
        current = current->next;
    }

    fclose(fp);
    return TRUE;
}

Team *get_team_list(void)
{
    FILE *fp = fopen("data/teams.dat", "rb");
    if (fp == NULL)
        return NULL;

    Team *first_team = NULL;
    Team *current_team = NULL;

    while (1)
    {
        Team *new_team = malloc(sizeof(Team));
        if (new_team == NULL)
        {
            fclose(fp);
            free_team_list(first_team);
            return NULL;
        }

        if (fread(new_team, sizeof(Team), 1, fp) != 1)
        {
            if (feof(fp))
            {
                free(new_team);
                break;
            }
            else
            {
                free(new_team);
                fclose(fp);
                free_team_list(first_team);
                return NULL;
            }
        }

        new_team->next = NULL;

        if (first_team == NULL)
        {
            first_team = new_team;
            current_team = first_team;
        }
        else
        {
            current_team->next = new_team;
            current_team = new_team;
        }
    }

    fclose(fp);
    return first_team;
}

void update_team_list(Team *list_team)
{
    FILE *fp = fopen("data/teams.dat", "wb");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo para salvar");
        return;
    }

    Team *current = list_team;
    while (current != NULL)
    {
        if (fwrite(current, sizeof(Team), 1, fp) != 1)
        {
            perror("Erro ao salvar equipe no arquivo");
            break;
        }
        current = current->next;
    }

    fclose(fp);
}

void free_team_list(Team *list_team)
{
    if (list_team == NULL)
        return;
    Team *temp;
    while (list_team)
    {
        temp = list_team;
        list_team = list_team->next;
        free(temp);
    }
}
