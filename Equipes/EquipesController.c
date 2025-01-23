#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../Usuarios/UsuariosModel.h"

#include "EquipesController.h"
#include "EquipeModel.h"
#include "EquipesView.h"

int create_team(void)
{
    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    Team *teams = (Team *)malloc(sizeof(Team));
    if (teams == NULL)
        return FALSE;

    memset(teams, 0, sizeof(Team));
    teams->status = ATIVO;
    teams->id = generate_id_team(&team_list) + 1;

    printf("|\tNome da equipe: ");
    char *name = read_string();
    strcpy(teams->name, name);

    printf("|\tDescrição da equipe: ");
    char *description = read_description();
    strcpy(teams->description, description);

    for (int i = 0; i < 10; i++)
    {
        teams->users[i][0] = '\0';
    }

    add_team_order(&team_list, teams);

    int result = save_team_list(&team_list);
    free_team_list(&team_list);

    return result;
}

int edit_team(const int id)
{
    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    if (team_list.start == NULL || !search_id_team(&team_list, id))
        return FALSE;

    Team *current_team = team_list.start;
    while (current_team != NULL)
    {
        if (current_team->id == id)
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

    update_team_list(&team_list);
    free_team_list(&team_list);
    return TRUE;
}

void show_all_teams(TeamList *team_list)
{

    Team *current_team = team_list->start;
    while (current_team != NULL)
    {
        menu_team_display(current_team);
        current_team = current_team->next;
    }
}

int teams_by_status(TeamList *team_list, const char status)
{
    int result = FALSE;
    Team *current_team = team_list->start;
    while (current_team != NULL)
    {
        if (current_team->status == status)
        {
            result = TRUE;
            menu_team_display(current_team);
        }
        current_team = current_team->next;
    }
    return result;
}

int team_by_user(TeamList *team_list, const int key)
{
    int result = FALSE;
    Team *current_team = team_list->start;

    while (current_team != NULL)
    {
        int has_user = FALSE;

        for (int i = 0; i < 10; i++)
        {
            if (current_team->users[i][0] != '\0')
            {
                has_user = TRUE;
                break;
            }
        }

        if (key == 0 && !has_user)
        {
            result = TRUE;
            menu_team_display(current_team);
        }
        else if (key == 1 && has_user)
        {
            result = TRUE;
            menu_team_display(current_team);
        }

        current_team = current_team->next;
    }

    return result;
}

int search_id_team(TeamList *team_list, const int id)
{
    Team *current_team = team_list->start;
    while (current_team != NULL)
    {
        if (current_team->id == id)
        {
            menu_team_display(current_team);
            return TRUE;
        }
        current_team = current_team->next;
    }
    return FALSE;
}

int modify_user_in_team(const int id, const int key)
{
    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);
    int result = FALSE;

    if (team_list.start == NULL || !search_id_team(&team_list, id))
        return result;

    Team *current_team = team_list.start;
    while (current_team != NULL)
    {
        if (current_team->id == id)
        {
            if (key == 1)
            {

                for (int i = 0; i < 10; i++)
                {
                    if (current_team->users[i][0] == '\0')
                    {
                        printf("|\tID do usuário: ");
                        int user_id;
                        scanf("%d", &user_id);

                        if (user_exists(NULL, user_id))
                        {
                            snprintf(current_team->users[i], sizeof(current_team->users[i]), "%d", user_id);
                            result = TRUE;
                            break;
                        }
                        else
                        {
                            show_error("Usuário não encontrado ou inválido!");
                            break;
                        }
                    }
                }
            }
            else if (key == 0)
            {

                printf("|\tID do usuário para remover: ");
                int user_id;
                scanf("%d", &user_id);

                for (int i = 0; i < 10; i++)
                {
                    if (current_team->users[i][0] != '\0' && atoi(current_team->users[i]) == user_id)
                    {
                        current_team->users[i][0] = '\0';
                        result = TRUE;
                        break;
                    }
                }

                if (!result)
                    show_error("Usuário não encontrado na equipe!");
            }
            break;
        }
        current_team = current_team->next;
    }

    update_team_list(&team_list);
    free_team_list(&team_list);
    return result;
}

void change_team_status(TeamList *team_list, const int id)
{
    Team *current_team = team_list->start;
    while (current_team != NULL)
    {
        if (current_team->id == id)
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
