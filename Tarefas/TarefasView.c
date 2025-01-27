#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TarefasController.h"
#include "TarefasView.h"

#include "../libs/validate.h"
#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"

int get_task_info(TaskInfo *task_info)
{
    char op;
    printf("|\tTarefa com responsabilidade de:\n\t[1] Usuário\n\t[2] Equipe\n\t[0] Voltar\n");
    scanf(" %c", &op);

    switch (op)
    {
    case '1':
        task_info->file_name = "./data/users_tasks.dat";
        printf("|\tID do usuário: ");
        scanf(" %d", &task_info->id);
        if (!user_exists(NULL, task_info->id))
        {
            show_error("Usuário não encontrado!");
            getchar();
            return FALSE;
        }
        return TRUE;
    case '2':
        task_info->file_name = "./data/teams_tasks.dat";
        printf("|\tID do time: ");
        scanf(" %d", &task_info->id);
        if (!team_exists(task_info->id))
        {
            show_error("Time não encontrado!");
            getchar();
            return FALSE;
        }
        return TRUE;
    case '0':
        return FALSE;
    default:
        show_error("Opção inválida!");
        return FALSE;
    }
}

char menu_task(void)
{
    char op;
    limpar_tela();
    printf("|---------------------------------------------------|\n");
    printf("|                     Tarefas                       |\n");
    printf("|---------------------------------------------------|\n");
    printf("|               [1] Cadastrar Tarefa                |\n");
    printf("|               [2] Exibir Tarefa                   |\n");
    printf("|               [3] Editar Tarefa                   |\n");
    printf("|               [4] Relatório de Tarefas            |\n");
    printf("|               [0] Sair                            |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void menu_task_register(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                              Cadastrar Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    TaskInfo task_info;
    if (!get_task_info(&task_info))
        return;

    if (register_task(task_info.file_name, task_info.id))
        show_sucess("| Tarefa cadastrada com sucesso!\n");
    else
        show_error("| [ERRO]: Erro ao cadastrar!\n");

    getchar();
    enter();
}

void menu_task_search(void)
{
    limpa_buffer();
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Exibir Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    //usar isso para pegar a informacao da tarefa
    TaskInfo task_info;
    if (!get_task_info(&task_info))
        return;

    TaskList task_list;
    get_task_list(&task_list, task_info.file_name);

    const char *name;
    if(strstr(task_info.file_name, "users") != NULL)
        name = "user";
    else 
        name = "team";

    if (!search_task(&task_list, task_info.id, name))
        show_error("Tarefa não encontrada");

    enter();
    free_task_list(&task_list);
}

void menu_task_edit(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Editar Tarefa                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    TaskInfo task_info;
    if (!get_task_info(&task_info))
        return;

    if (!edit_task(task_info.file_name, task_info.id))
        show_error("Processo de edição não concluído!");

    enter();
}

int chose_task_to_show(){
    char op;
    int id;
    printf("\nTarefa de usuário ou equipe:\n[1]Usuário \n[2]Equipe\n");
    scanf(" %c", &op);

    switch (op)
    {
    case '1':
        printf("Id do usuário: ");
        scanf(" %d", &id);
        limpa_buffer();
        break;
    case '2':
        printf("Id da equipe: ");
        scanf(" %d", &id);
        limpa_buffer();
        break;
    default:
        printf("\nOpção inválida!\n");
    }
    return id;
}

void menu_task_reports(void)
{
    limpar_tela();

    char opc;

    TaskList task_teams;
    create_task_list(&task_teams);
    get_task_list(&task_teams, "./data/teams_tasks.dat");
    TaskList task_users;
    create_task_list(&task_users);
    get_task_list(&task_users, "./data/users_tasks.dat");

    do
    {
        printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
        printf("|                                                              Relatorio de Tarefa                                                              |\n");
        printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
        printf("|[1] -> Tarefas não concluidas\n");
        printf("|[2] -> Tarefas concluídas\n");
        printf("|[3] -> Tarefas por usuários\n");
        printf("|[4] -> Tarefas com times\n");
        printf("|[5] -> Todas as tarefas\n");
        printf("|[6] -> Tarefas em atraso\n");
        printf("|[7] -> Tarefas em andamento\n");
        printf("|[0] -> Voltar\n");
        scanf(" %c", &opc);

        switch (opc)
        {
        case '1':
            printf("|\t\t\033[1;33mTarefas de equipes não concluídas\033[0m: \n");
            if (!tasks_by_status(&task_teams, ATIVO, "team"))
                show_error("Sem tarefas não concluídas!");
            printf("|\t\t\033[1;33mTarefas de usuários não concluídas:\033[0m \n");
            if (!tasks_by_status(&task_users, ATIVO, "user"))
                show_error("Sem tarefas não concluídas!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '2':
            printf("|\t\t\033[1;33mTarefas de equipes concluídas:\033[0m \n");
            if (!tasks_by_status(&task_teams, INATIVO, "team"))
                show_error("Sem tarefas sem tarefas conluídas!");
            printf("|\t\t\033[1;33mTarefas de usuários concluídas:\033[0m \n");
            if (!tasks_by_status(&task_users, INATIVO, "user"))
                show_error("Sem tarefas sem tarefas conluídas!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '3':
            if (!show_tasks(&task_users, "user"))
                show_error("Sem tarefas atribuídas a usuários!");
            break;
        case '4':
            if (!show_tasks(&task_teams, "team"))
                show_error("Sem tarefas atribuídas a equipes!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '5':
            printf("|\t\t\033[1;33mTarefas de usuários\033[0m        \n");
            if (!show_tasks(&task_users, "user"))
                show_error("Sem tarefas!");
            printf("|\t\t\033[1;33mTarefas de equipes\033[0m       \n");
            if (!show_tasks(&task_teams, "team"))
                show_error("Sem tarefas!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '6':
            printf("|\t\t\033[1;33mTarefas de equipes pendentes\033[0m        \n");
            if (!overdue_tasks(&task_teams, "team"))
                show_error("Sem tarefas pendentes!");
            printf("|\t\t\033[1;33mTarefas de usuários pendentes\033[0m        \n");
            if (!overdue_tasks(&task_users, "user"))
                show_error("Sem tarefas pendentes!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '7':
            printf("|\t\t\033[1;33mTarefas de equipes em andamento\033[0m        \n");
            int id =chose_task_to_show();
            if (!in_progress_tasks(&task_teams, id, "team"))
                show_error("Sem tarefas em andamento!");
            printf("|\t\t\033[1;33mTarefas de usuários em andamento\033[0m       \n");
            if (!in_progress_tasks(&task_users, id, "user"))
                show_error("Sem tarefas em andamento!");
            enter();
            getchar();
            limpar_tela();
            break;
        case '0':
            return;
        default:
            show_error("Opção inválida!");
        }

    } while (opc != '0');

    enter();
    free_task_list(&task_teams);
    free_task_list(&task_users);
}

void display_data_task(Task *task, const char *name)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados da Tarefa                                                               |\n");
    printf("| \033[1mID:\033[0m %d\n", task->id);

    if (strcmp(name, "team") == 0)
        show_data('2', task->responsible_id);
    else if (strcmp(name, "user") == 0)
        show_data('1', task->responsible_id);
    else 
        printf("| \033[1mResponsável:\033[0m %d\n", task->responsible_id);

    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\033[1m\tTarefa:\033[m %s\n", task->title);
    printf("|\033[1m\tDescrição:\033[m %s\n", task->description);
    printf("|\033[1m\tData:\033[m %s\n", task->date);
    printf("|\033[1m\tPrioridade:\033[m %s\n", task->priority == ALTA ? "Alta" : task->type == MEDIA ? "Média"
                                                                                                     : "Baixa");
    printf("|\033[1m\tTipo:\033[m %s\n", task->type == EVENTO ? "Evento" : task->type == REUNIAO ? "Reunião"
                                                                                                 : "Projeto");
    printf("|\033[1m\tStatus:\033[0m %s\n", task->status == INATIVO ? "Fechada" : "Ativa");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
