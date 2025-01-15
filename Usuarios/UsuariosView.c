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
    printf("|                [2] Exibir Dados                |\n");
    printf("|                [3] Editar Dados                |\n");
    printf("|                [4] Excluir Conta               |\n");
    printf("|                [5] Reativar Conta              |\n");
    printf("|                [6] Relatório de Usuários       |\n");
    printf("|                [0] Sair                        |\n");
    printf("--------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    limpar_tela();
    limpa_buffer();
    return op;
}

void register_user()
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

User *initialize_user(const char status)
{
    printf("|\tCPF:\t");
    const char *cpf = read_cpf();
    User *user = load_user(cpf);

    if (user == NULL)
    {
        show_error("| CPF nao encontrado");
        return NULL;
    }
    else if (user->status == status)
    {
        show_error("| Nao é possível acessar esse usuário");
        return NULL;
    }

    return user;
}

void search_user(void)
{
    show_header("Exibir Dados");
    User *user = initialize_user(INATIVO);

    if (user != NULL)
        display_data_user(user);

    enter();
}

void modify_user_data(void)
{
    show_header("Editar Dados");
    User *user = initialize_user(INATIVO);

    if (user != NULL)
    {
        display_data_user(user);
        edit_user(user);
    }

    enter();
}

void delete_user(void)
{
    show_header("Excluir Conta");
    User *user = initialize_user(INATIVO);

    if (user != NULL)
    {
        display_data_user(user);
        user->status = INATIVO;
        update_user(user);
        remove_user_inactive_teams(user->id);
        show_sucess("Usuário desativado");
    }
    enter();
}

void reactivate_user(void)
{
    show_header("Reativar Conta");
    User *user = initialize_user(ATIVO);

    if (user != NULL)
    {
        display_data_user(user);
        user->status = ATIVO;
        update_user(user);
        show_sucess("Usuário ativado");
    }

    enter();
}

void show_users(void)
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

    switch (op)
    {
    case '1':
        report_users(TODOS);
        break;
    case '2':
        report_users(ATIVO);
        break;
    case '3':
        report_users(INATIVO);
        break;
    case '0':
        break;
    default:
        show_error("Opção inválida!");
        break;
    }

    enter();
    getchar();
}

void display_data_user(const User *user)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\t\t\033[1m-> Dados do Usuário\033[m \n");
    printf("\033[1m|ID:\033[m %s\n", user->id);
    printf("\033[1m|CPF:\033[m %s\n", user->cpf);
    printf("\033[1m|Nome:\033[m %s\n", user->name);
    printf("\033[1m|Telefone:\033[m %s\n", user->phone);
    printf("\033[1m|Definicoes:\033[m %s\n", user->status == ATIVO ? "Ativo" : "Inativo");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
