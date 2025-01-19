#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"

#include "EquipesView.h"
#include "EquipesController.h"

char menu_team(void)
{
    char op;
    limpar_tela();
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("|                       Equipes                    |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Equipe               |\n");
    printf("|               [2] Pesquisar Equipe               |\n");
    printf("|               [3] Mudar status da Equipe         |\n");
    printf("|               [4] Editar Equipe                  |\n");
    printf("|               [5] Editar Usuário na Equipe       |\n");
    printf("|               [6] Relatorio de Equipes           |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void menu_team_register(void)
{
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Cadastro de equipe acadêmica                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    if (create_team())
        show_sucess("Sucesso ao registrar a equipe!");
    else
        show_error("[ERROR] Falha ao cadastrar a equipe!");

    limpa_buffer();
}

void menu_search_team(void)
{
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Exibir equipe                                                                   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    if (team_list.start == NULL)
    {
        show_error("Nenhuma equipe cadastrada!");
        return;
    }

    printf("|\tID da equipe: ");
    int id;
    scanf("%d", &id);

    if (!search_id_team(&team_list, id))
    {
        show_error("Equipe não encontrada!");
        return;
    }

    limpa_buffer();
    enter();
    free_team_list(&team_list);
}

void menu_team_status(void)
{
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                          Mudar status da equipe                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    if (team_list.start == NULL)
    {
        show_error("Nenhuma equipe cadastrada!");
        return;
    }

    printf("|\tID da equipe: ");
    int id;
    scanf("%d", &id);

    if (!search_id_team(&team_list, id))
    {
        show_error("Equipe não encontrada!");
        return;
    }

    change_team_status(&team_list, id);

    enter();
    getchar();
    free_team_list(&team_list);
}

void menu_team_edit(void)
{
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Editar equipe                                                                   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\tID da equipe: ");
    int id;
    scanf("%d", &id);

    if (!edit_team(id))
    {
        show_error("Equipe não encontrada!");
        return;
    }

    enter();
}

void menu_team_user_edit(void)
{
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Editar usuário na equipe                                                        |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    if (team_list.start == NULL)
    {
        show_error("Nenhuma equipe cadastrada!");
        return;
    }

    printf("|\tID da equipe: ");
    int id;
    scanf(" %d", &id);
    char op;

    do
    {
        limpa_buffer();
        printf("|\t [1] Adicionar usuário na equipe\n");
        printf("|\t [2] Remover usuário da equipe\n");
        printf("|\t [0] Sair\n");
        printf("\nEscolha a opção desejada: ");
        scanf(" %c", &op);
        switch (op)
        {
        case '1':
            if (modify_user_in_team(id, ADICIONAR))
                show_sucess("Usuário adicionado com sucesso!");
            else
                show_error("Erro ao adicionar o usuário!");
            break;
        case '2':
            if (modify_user_in_team(id, REMOVER))
                show_sucess("Usuário removido com sucesso!");
            else
                show_error("Erro ao remover o usuário!");
            break;
        case '0':
            break;
        default:
            show_error("Opção inválida!");
            break;
        }

    } while (op != '0');

    enter();
}

void menu_team_report(void)
{
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Relatório de Equipes                                                            |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|[1] -> Listar Equipes\n");
    printf("|[2] -> Equipes ativas\n");
    printf("|[3] -> Equipes inativas\n");
    printf("|[4] -> Equipes com usuários\n");
    printf("|[5] -> Equipes sem usuários\n");
    printf("|[0] -> Voltar\n");

    TeamList team_list;
    create_list_team(&team_list);
    get_list_team(&team_list);

    if (team_list.start == NULL)
    {
        show_error("Nenhuma equipe cadastrada!");
        return;
    }

    printf("Escolha a opção desejada: ");
    char op;
    scanf("%c", &op);
    switch (op)
    {
    case '1':
        show_all_teams(&team_list);
        break;
    case '2':
        teams_by_status(&team_list, ATIVO);
        break;
    case '3':
        teams_by_status(&team_list, INATIVO);
        break;
    case '4':
        printf("Em desenvolvimento");
        break;
    case '5':
        printf("Em desenvolvimento");
        break;
    case '0':
        break;
    default:
        show_error("Opção inválida!");
        break;
    }
    limpa_buffer();
    enter();
    free_team_list(&team_list);
}

void menu_team_display(const Team *teams)
{
    printf("|\t\t\033[1m-> Dados do Time\033[m \n");
    printf("\033[1m|ID:\033[m %d\n", teams->id);
    printf("\033[1m|Usuários:\033[m\n");
    for (int i = 0; i < 10; i++)
    {
        if (teams->users[i][0] != '\0')
        {
            printf("\t-> %s\n", teams->users[i]);
        }
    }
    printf("\033[1m|Nome da equuipe:\033[m %s\n", teams->name);
    printf("\033[1m|Descrição:\033[m %s\n", teams->description);
    printf("\033[1m|Status:\033[m %s\n", teams->status == ATIVO ? "Ativa" : "Inativa");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}

void feedback_team(Team *team, const char *error_message, const char *success_message)
{
    if (team == NULL)
    {
        show_error(error_message);
    }
    else
    {
        show_sucess(success_message);
    }
}
