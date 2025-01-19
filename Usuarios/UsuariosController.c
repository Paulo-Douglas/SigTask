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

    create_list(&user_list);
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

    if (user_exists(new_user->cpf))
    {
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

    User *aux = user_list.start;
    while (aux->next != NULL)
    {
        printf("|\tID: %d\n", aux->id);
        printf("|\tCPF: %s\n", aux->cpf);
        printf("|\tNome: %s\n", aux->name);
        printf("|\tTelefone: %s\n", aux->phone);
        printf("|\tStatus: %s\n", aux->status == ATIVO ? "Ativo" : "Inativo");
        aux = aux->next;
    }

    int result = save_user_list(&user_list);
    return result;
}

int edit_user(const int id)
{
    UserList list;
    create_list(&list);
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

void show_all_users(User *lista)
{
    User *usuario_atual = lista;
    while (usuario_atual != NULL)
    {
        user_menu_display(usuario_atual);
        usuario_atual = usuario_atual->next;
    }
}

void users_by_status(User *lista, const char status)
{
    User *usuario_atual = lista;
    while (usuario_atual != NULL)
    {
        if (usuario_atual->status == status)
        {
            user_menu_display(usuario_atual);
        }
        usuario_atual = usuario_atual->next;
    }
}

int search_id_user(User *lista, const int id)
{
    User *current_user = lista;
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

void change_status_user(User *user, const int id)
{
    User *current_user = user;
    while (current_user != NULL)
    {
        if (id == current_user->id)
        {
            if (current_user->status == ATIVO)
            {
                current_user->status = INATIVO;
                feedback_user(current_user, "Erro ao alterar o status", "Status alterado com sucesso");
            }
            else
            {
                current_user->status = ATIVO;
                feedback_user(current_user, "Erro ao alterar o status", "Status alterado com sucesso");
            }
        }
        current_user = current_user->next;
    }
    // update_user_list(user);
}
