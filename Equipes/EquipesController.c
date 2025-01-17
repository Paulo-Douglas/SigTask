#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

#include "EquipesController.h"
#include "EquipeModel.h"
#include "EquipesView.h"

int create_team(void)
{
    Team *teams = (Team *)malloc(sizeof(Team));
    if (teams == NULL)
    {
        show_error("Não foi possível alocar memória para time");
        return FALSE;
    }

    printf("|\tNome da equipe: ");
    char *name = read_string();
    strcpy(teams->name, name);

    printf("|\tDescrição da equipe: ");
    char *description = read_string();
    strcpy(teams->description, description);

    teams->status = ATIVO;

    for (int i = 0; i < 10; i++)
    {
        teams->users[i][0] = '\0';
    }

    int result = insert_team(teams);

    return result;
}

void edit_team(Team *team_list, const char id[4])
{
    Team *current_team = team_list;
    while (current_team != NULL)
    {
        if (strcmp(current_team->id, id) == 0)
        {
            limpa_buffer();
            printf("|\tNome da equipe: ");
            char *name = read_string();
            strcpy(current_team->name, name);

            printf("|\tDescrição da equipe: ");
            char *description = read_string();
            strcpy(current_team->description, description);

            break;
        }
        current_team = current_team->next;
    }

    update_team_list(team_list);
}

void show_all_teams(Team *team_list)
{
    Team *current_team = team_list;
    while (current_team != NULL)
    {
        menu_team_display(current_team);
        current_team = current_team->next;
    }
}

void teams_by_status(Team *team_list, const char status)
{
    Team *current_team = team_list;
    while (current_team != NULL)
    {
        if (current_team->status == status)
        {
            menu_team_display(current_team);
        }
        current_team = current_team->next;
    }
}

void team_by_user(Team *team_list, const char *key)
{
    printf("Em desenvolvimento");
}

int search_id_team(Team *team_list, const char *id)
{
    Team *current_team = team_list;
    while (current_team != NULL)
    {
        if (strcmp(current_team->id, id) == 0)
        {
            menu_team_display(current_team);
            return TRUE;
        }
        current_team = current_team->next;
    }
    return FALSE;
}

void add_user_to_team(Team *team_list, const char id[4])
{
    printf("Em desenvolvimento");
}

void change_team_status(Team *team_list, const char id[4])
{
    Team *current_team = team_list;
    while (current_team != NULL)
    {
        if (strcmp(current_team->id, id) == 0)
        {
            if (current_team->status == ATIVO)
            {
                current_team->status = INATIVO;
                feedback_team(current_team, "Erro ao alterar o status", "Status alterado com sucesso");
            }
            else
            {
                current_team->status = ATIVO;
                feedback_team(current_team, "Erro ao alterar o status", "Status alterado com sucesso");
            }
        }
        current_team = current_team->next;
    }
    update_team_list(team_list);
}