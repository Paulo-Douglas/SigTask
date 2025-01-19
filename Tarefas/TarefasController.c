#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TarefasController.h"
#include "TarefasView.h"
#include "TarefasModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"

char *responsible(void)
{
    printf("|\tTarefa destinado a:\n");
    printf("|\t[1] Usuário\n\t[2] Equipe\n");

    char *choice = (char *)malloc(4 * sizeof(char));
    char op;

    scanf(" %c", &op);

    switch (op)
    {
    case '1':
        printf("ID do usuário: \n");
        scanf("%4s", choice);
        // if (user_exists(choice))
        // {
        //     strcat(choice, "U");
        //     return choice;
        // };
        break;
    case '2':
        printf("ID do time: \n");
        scanf("%4s", choice);
        // if (team_exists(choice))
        // {
        //     strcat(choice, "T");
        //     return choice;
        // };
        break;
    default:
        show_error("Opção inválida.");
        break;
    }

    return NULL;
}

int register_task(void)
{
    limpa_buffer();
    int year = year_now();

    Task task = {0};

    char *id = responsible();
    if (id == NULL)
        return FALSE;

    strcpy(task.responsible, id);

    limpa_buffer();
    printf("|\tTítulo: ");
    char *title = read_string();
    strcpy(task.title, title);

    printf("|\tDescrição: ");
    char *description = read_string();
    strcpy(task.description, description);

    limpa_buffer();
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\tData: \n");
    read_date(day, month);
    snprintf(task.date, 12, "%s/%s/%d", day, month, year);

    if (check_dates(task.date))
    {
        show_error("Data não pode ser menor que a data atual!");
        return FALSE;
    }

    limpa_buffer();
    printf("\tTipo de Tarefa: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
    char type = read_generic_123("type");
    task.type = type;

    printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
    char priority = read_generic_123("priority");
    task.priority = priority;

    task.status = '1';

    int result = insert_task(&task);

    return result;
}

void edit_task(Task *task)
{
    limpa_buffer();

    int year = year_now();
    char opc;
    int result = FALSE;

    do
    {
        printf("Opção de edição:\n");
        printf("[1] Responsável\n");
        printf("[2] Título\n");
        printf("[3] Descrição\n");
        printf("[4] Data\n");
        printf("[5] Prioridade\n");
        printf("[6] Tipo\n");
        printf("[0] Sair\n");
        scanf(" %c", &opc);

        switch (opc)
        {
        case '1':
            limpa_buffer();
            char *id = responsible();
            strcpy(task->responsible, id);
            result = update_task(task);
            result ? show_sucess("Responsável editado com sucesso!") : show_error("Erro ao editar o responsável");
        case '2':
            limpa_buffer();
            printf("|\tTítulo: ");
            char *title = read_string();
            strcpy(task->title, title);
            result = update_task(task);
            result ? show_sucess("Título editado com sucesso!") : show_error("Erro ao editar o titulo");
        case '3':
            limpa_buffer();
            printf("|\tDescrição: ");
            char *description = read_string();
            strcpy(task->description, description);
            result = update_task(task);
            result ? show_sucess("Descrição editada com sucesso!") : show_error("Erro ao editar a descrição");
            break;
        case '4':
            limpa_buffer();
            char day[MAX_DAY_LENGHT];
            char month[MAX_MONTH_LENGHT];
            printf("\tData: \n");
            read_date(day, month);
            snprintf(task->date, 12, "%s/%s/%d", day, month, year);
            result = update_task(task);
            result ? show_sucess("Data editada com sucesso!") : show_error("Erro ao editar a data");
            break;
        case '5':
            limpa_buffer();
            printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
            char priority = read_generic_123("priority");
            task->priority = priority;
            result = update_task(task);
            result ? show_sucess("Prioridade editada com sucesso!") : show_error("Erro ao editar a prioridade");
            break;
        case '6':
            limpa_buffer();
            printf("\tTipo de Tarefa: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
            char type = read_generic_123("type");
            task->type = type;
            result = update_task(task);
            result ? show_sucess("Tipo editado com sucesso!") : show_error("Erro ao editar o tipo");
            break;
        case '0':
            break;
        default:
            show_error("Opção inválida.");
            break;
        }

    } while (opc != '0');
}