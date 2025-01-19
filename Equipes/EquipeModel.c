#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/styles.h"

#include "EquipeModel.h"
#include "EquipesView.h"

int generate_id_team(TeamList *list)
{
    int max_id = 0;

    Team *current = list->start;
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

void create_list_team(TeamList *list)
{
    list->start = NULL;
    list->lenght = 0;
}

void add_team_start(TeamList *list, Team *team)
{
    team->next = list->start;
    list->start = team;
    list->lenght++;
}

void add_team_end(TeamList *list, Team *team)
{
    if (list->start == NULL)
        add_team_start(list, team);
    else
    {
        Team *aux = list->start;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = team;
    }
    list->lenght++;
}

void add_team_order(TeamList *list, Team *team)
{
    if (list->start == NULL || strcmp(list->start->name, team->name) > 0)
        add_team_start(list, team);
    else
    {
        Team *aux = list->start;
        while (aux->next != NULL && strcmp(aux->next->name, team->name) < 0)
            aux = aux->next;
        team->next = aux->next;
        aux->next = team;
    }
    list->lenght++;
}

void get_list_team(TeamList *list)
{
    FILE *fp = fopen("data/teams.dat", "rb");
    if (!fp)
        return;

    while (!feof(fp))
    {
        Team *new_team = (Team *)malloc(sizeof(Team));
        if (fread(new_team, sizeof(Team), 1, fp) != 1)
        {
            free(new_team);
            break;
        }
        new_team->next = NULL;
        add_team_end(list, new_team);
    }
    fclose(fp);
}

int save_team_list(TeamList *list)
{
    create_path("data/");
    FILE *fp = fopen("data/teams.dat", "wb");
    if (!fp)
        return FALSE;

    Team *aux = list->start;
    while (aux != NULL)
    {
        if (fwrite(aux, sizeof(Team), 1, fp) != 1)
        {
            perror("Erro ao escrever no arquivo");
            fclose(fp);
            return FALSE;
        }
        aux = aux->next;
    }

    fclose(fp);
    return TRUE;
}

void update_team_list(TeamList *list)
{
    FILE *fp = fopen("data/teams.dat", "wb");
    if (!fp)
        return;

    Team *aux = list->start;
    while (aux != NULL)
    {
        fwrite(aux, sizeof(Team), 1, fp);
        aux = aux->next;
    }
    fclose(fp);
}

void free_team_list(TeamList *list)
{
    Team *aux = list->start;
    while (aux != NULL)
    {
        Team *next = aux->next;
        free(aux);
        aux = next;
    }
}