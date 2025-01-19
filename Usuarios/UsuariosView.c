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
    UserList list;
    create_list(&list);
    get_list_user(&list);

    printf("|\tID do usuário: ");
    int id;
    scanf("%d", &id);

    if (!search_id_user(list.start, id))
        show_error("Usuário não encontrado!");

    enter();
    getchar();
    free_user_list(&list);
}

void user_menu_edit(void)
{
    show_header("Editar Dados");

    printf("|\tID do usuário: ");
    int id;
    scanf("%d", &id);

    if (!edit_user(id))
    {
        show_error("Erro ao editar o usuário");
        return;
    }

    enter();
    getchar();
}

void user_menu_status(void)
{
    show_header("Mudar status da Conta");
    UserList list;
    create_list(&list);
    get_list_user(&list);

    printf("|\tID do usuário: ");
    int id;
    scanf("%d", &id);

    if (!search_id_user(list.start, id))
        show_error("Usuário não encontrado!");

    change_status_user(&list, id);
    enter();
    getchar();
    free_user_list(&list);
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

    UserList list;
    create_list(&list);
    get_list_user(&list);

    if (list.start == NULL)
    {
        show_error("Nenhum usuário cadastrado!");
        return;
    }

    switch (op)
    {
    case '1':
        show_all_users(&list);
        break;
    case '2':
        users_by_status(&list, ATIVO);
        break;
    case '3':
        users_by_status(&list, INATIVO);
        break;
    case '0':
        break;
    default:
        show_error("Opção inválida!");
        break;
    }

    enter();
    getchar();
    free_user_list(&list);
}

void user_menu_display(const User *user)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\t\t\033[1m-> Dados do Usuário\033[m \n");
    printf("\033[1m|ID:\033[m %d\n", user->id);
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
