#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UsuariosController.h"
#include "UsuariosModel.h"
#include "../libs/reads.h"
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"

int create_user(void)
{
    User *new_user = (User *)malloc(sizeof(User));
    if (!new_user)
    {
        show_error("Não foi possível alocar memória para o usuário");
        return FALSE;
    }

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

    printf("|\tTelefone: ");
    char *phone = read_phone();
    if (!phone)
    {
        free(new_user);
        return FALSE;
    }
    strcpy(new_user->phone, phone);
    free(phone);

    new_user->status = '1';
    new_user->next = NULL;

    int result = insert_user(new_user);

    return result;
}

void edit_user(User *user)
{
    char op;
    int result = FALSE;

    do
    {
        printf("|\t[1] Editar nome\n");
        printf("|\t[2] Editar telefone\n");
        printf("|\t[0] Sair\n");
        scanf(" %c", &op);

        switch (op)
        {
        case '1':
            printf("%s", user->cpf);
            limpa_buffer();
            printf("|\tNome: ");
            char *name = read_string();
            strcpy(user->name, name);
            result = update_user(user);
            result ? show_sucess("Nome editado com sucesso!") : show_error("Erro ao editar o nome");
            break;
        case '2':
            printf("|\tTelefone: ");
            char *phone = read_phone();
            strcpy(user->phone, phone);
            result = update_user(user);
            result ? show_sucess("Telefone editado com sucesso!") : show_error("Erro ao editar o telefone");
            break;
        case '0':
            break;
        default:
            show_error("É preciso digitar uma opção válida!");
        }
    } while (op != '0');
}
