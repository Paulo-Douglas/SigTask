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

/**
 * Exibe o menu de usuários com opções para cadastrar, exibir dados,
 * editar dados, excluir conta, reativar conta ou sair.
 *
 * @return O caractere que representa a opção de menu escolhida.
 */
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

/**
 * Exibe a tela de cadastro de usuários.
 *
 * Se o cadastro for efetuado com sucesso, exibe mensagem de sucesso.
 * Caso contrário, exibe mensagem de erro e informa que o CPF ja esta cadastrado ou
 * que houve um erro ao cadastrar.
 *
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 */
void register_user()
{
    show_header("Cadastrar Usuário");

    if (add_user())
    {
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_sucess("| Cadastrado com sucesso!\n");
    }
    else
    {
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        show_error("| [ERRO]: CPF ja cadastrado ou erro ao cadastrar!\n");
    }
    enter();
}

User *struct_user(const char status)
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

/**
 * Exibe a tela de exibir dados dos usuários.
 *
 * Esta tela apenas exibe os dados dos usuários sem realizar nenhuma ação.
 *
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 */
void search_user(void)
{
    show_header("Exibir Dados");
    User *user = struct_user('0');

    if (user != NULL)
        display_data_user(user);

    enter();
}

/**
 * Exibe a tela de alterar dados dos usuários.
 *
 * Esta tela pede o CPF do usuário e, se encontrado, permite alterar os dados do usuário.
 *
 * A tela aguarda que o usuário tecle <ENTER> para continuar.
 *
 **/
void modify_user_data(void)
{
    show_header("Editar Dados");
    User *user = struct_user('0');

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
    User *user = struct_user('0');

    if (user != NULL)
    {
        display_data_user(user);
        user->status = '0';
        update_user(user);
        remove_user_inactive_teams(user->id);
        printf("sai");
        show_sucess("Usuário desativado");
    }
    enter();
}

void reactivate_user(void)
{
    show_header("Reativar Conta");
    User *user = struct_user('1');

    if (user != NULL)
    {
        display_data_user(user);
        user->status = '1';
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
        report_users('\0');
        break;
    case '2':
        report_users('1');
        break;
    case '3':
        report_users('0');
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
    printf("\033[1m|Status:\033[m %s\n", user->status == '1' ? "Ativo" : "Inativo");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
