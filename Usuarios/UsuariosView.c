#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "UsuariosView.h"
#include "UsuariosController.h"
#include "UsuariosModel.h"

#include "../Equipes/EquipeModel.h"
#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"

char user_menu(void)
{
    char op;
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                     Usuários                   |\n");
    printf("--------------------------------------------------\n");
    printf("|                [1] Cadastre - se               |\n");
    printf("|                [2] Buscar Usuário              |\n");
    printf("|                [3] Editar Dados                |\n");
    printf("|                [4] Mudar status da Conta       |\n");
    printf("|                [5] Relatório de Usuários       |\n");
    printf("|                [0] Sair                        |\n");
    printf("--------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    limpar_tela();
    limpa_buffer();
    return op;
}

void user_menu_register()
{
    show_header("Cadastrar Usuário");

    int result = create_user();
    if (result)
    {
        show_sucess("Usuário cadastrado com sucesso!");
    }
    else
    {
        show_error("Erro ao cadastrar o usuário");
    }

    enter();
}

void user_menu_search(void)
{
    show_header("Exibir Dados");

    User *users = get_user_list();

    if (users == NULL)
    {
        show_error("Lista de usuários indisponivel!");
        return;
    }

    printf("|\tID do usuário: ");
    char id[4];
    scanf("%4s", id);

    if (!search_id_user(users, id))
    {
        show_error("Usuário não encontrado!");
        return;
    }

    free_user_list(users);
    enter();
    getchar();
}

void user_menu_edit(void)
{
    show_header("Editar Dados");
    User *users = get_user_list();

    feedback_user(users, "Erro ao acessar a lista", "Lista gerada <Enter>");

    printf("|\tID do usuário: ");
    char id[4];
    scanf("%4s", id);

    if (!search_id_user(users, id))
    {
        show_error("Usuário não encontrado!");
        return;
    }

    edit_user(users, id);
    free_user_list(users);
    enter();
    getchar();
}

void user_menu_status(void)
{
    show_header("Excluir Conta");
    User *users = get_user_list();

    if (users == NULL)
    {
        show_error("Lista de usuários indisponivel!");
        return;
    }

    printf("|\tID do usuário: ");
    char id[4];
    scanf("%4s", id);

    if (!search_id_user(users, id))
    {
        show_error("Usuário não encontrado!");
        return;
    }

    change_status_user(users, id);
    free_user_list(users);
    enter();
}

void user_menu_reports(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                   Relatório                                                                   |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|[1] -> Todos os Usuários\n");
    printf("|[2] -> Usuários Ativos\n");
    printf("|[3] -> Usuários Inativos\n");
    printf("|[0] -> Voltar\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    char op;
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    limpar_tela();
    User *user_list = get_user_list();

    if (user_list == NULL)
    {
        show_error("Nenhum usuário cadastrado!");
        return;
    }

    switch (op)
    {
    case '1':
        show_all_users(user_list);
        break;
    case '2':
        users_by_status(user_list, ATIVO);
        break;
    case '3':
        users_by_status(user_list, INATIVO);
        break;
    case '0':
        break;
    default:
        show_error("Opção inválida!");
        break;
    }

    free_user_list(user_list);
    enter();
    getchar();
}

void user_menu_display(const User *user)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\t\t\033[1m-> Dados do Usuário\033[m \n");
    printf("\033[1m|ID:\033[m %s\n", user->id);
    printf("\033[1m|CPF:\033[m %s\n", user->cpf);
    printf("\033[1m|Nome:\033[m %s\n", user->name);
    printf("\033[1m|Telefone:\033[m %s\n", user->phone);
    printf("\033[1m|Status:\033[m %s\n", user->status == ATIVO ? "Ativo" : "Inativo");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}

void feedback_user(User *current_user, const char *error_message, const char *success_message)
{
    if (current_user == NULL)
    {
        show_error(error_message);
        getchar();
    }
    else
    {
        show_sucess(success_message);
        getchar();
    }
}
