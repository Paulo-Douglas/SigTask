#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UsuariosController.h"
#include "UsuariosModel.h"
#include "UsuariosView.h"
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

int create_user(void)
{
    UserList user_list;
    User *new_user = malloc(sizeof(User));

    if (!new_user)
        return FALSE;
    memset(new_user, 0, sizeof(User));

    create_list_user(&user_list);
    get_list_user(&user_list);

    printf("|\tCPF [XXX.XXX.XXX-XX]: ");
    char *cpf = read_cpf();
    if (!cpf)
    {
        free(new_user);
        return FALSE;
    }
    strcpy(new_user->cpf, cpf);
    free(cpf);

    if (user_exists(new_user->cpf, 0))
    {
        show_error("Usuário ja cadastrado!");
        free(new_user);
        return FALSE;
    }

    printf("|\tNome: ");
    char *name = read_string();
    if (!name)
    {
        free(new_user);
        return FALSE;
    }
    strcpy(new_user->name, name);
    free(name);

    printf("|\tTelefone [XX X XXXXXXX]: ");
    char *phone = read_phone();
    if (!phone)
    {
        free(new_user);
        return FALSE;
    }
    strcpy(new_user->phone, phone);
    free(phone);

    new_user->status = ATIVO;
    new_user->id = generate_user_id(&user_list) + 1;
    add_user_order(&user_list, new_user);

    int result = save_user_list(&user_list);
    free_user_list(&user_list);
    return result;
}

int edit_user(const int id)
{
    UserList list;
    create_list_user(&list);
    get_list_user(&list);

    if (list.start == NULL || !search_id_user(list.start, id))
        return FALSE;

    User *current_user = list.start;
    while (current_user != NULL)
    {
        if (id == current_user->id)
        {
            printf("Opção de edição:\n");
            printf("[1] Nome\n");
            printf("[2] Telefone\n");
            printf("[0] Sair\n");
            char op;
            scanf(" %c", &op);
            switch (op)
            {
            case '1':
                change_name(current_user);
                feedback_user(current_user, "Erro ao alterar o nome", "Nome alterado com sucesso");
                break;
            case '2':
                change_phone(current_user);
                feedback_user(current_user, "Erro ao alterar o telefone", "Telefone alterado com sucesso");
                break;
            default:
                break;
            }
        }
        current_user = current_user->next;
    }
    update_user_list(&list);
    free_user_list(&list);
    return TRUE;
}

void change_name(User *user)
{
    limpa_buffer();
    printf("|\tNome: ");
    char *name = read_string();
    if (name)
    {
        memset(user->name, '\0', sizeof(user->name));
        strcpy(user->name, name);
        free(name);
    }
}

void change_phone(User *user)
{
    limpa_buffer();
    printf("|\tTelefone [XX X XXXXXXX]: ");
    char *phone = read_phone();
    if (phone)
    {
        strcpy(user->phone, phone);
        free(phone);
    }
}

void show_all_users(UserList *list)
{
    User *usuario_atual = list->start;
    while (usuario_atual != NULL)
    {
        user_menu_display(usuario_atual);
        usuario_atual = usuario_atual->next;
    }
}

int users_by_status(UserList *list, const char status)
{
    int result = FALSE;
    User *usuario_atual = list->start;
    while (usuario_atual != NULL)
    {
        if (usuario_atual->status == status)
        {
            result = TRUE;
            user_menu_display(usuario_atual);
        }
        usuario_atual = usuario_atual->next;
    }
    return result;
}

int search_id_user(User *list, const int id)
{
    User *current_user = list;
    while (current_user != NULL)
    {
        if (id == current_user->id)
        {
            user_menu_display(current_user);
            return TRUE;
        }
        current_user = current_user->next;
    }
    return FALSE;
}

void change_status_user(UserList *list, const int id)
{
    if (list == NULL || list->start == NULL)
    {
        printf("A lista de usuários está vazia ou não inicializada.\n");
        return;
    }

    User *current_user = list->start;
    while (current_user != NULL)
    {
        if (id == current_user->id)
        {

            current_user->status = (current_user->status == ATIVO) ? INATIVO : ATIVO;

            feedback_user(
                current_user,
                "Erro ao alterar o status",
                "Status alterado com sucesso");

            break;
        }
        current_user = current_user->next;
    }

    update_user_list(list);
}
