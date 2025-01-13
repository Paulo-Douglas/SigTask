#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TarefasController.h"
#include "TarefasView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"

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
    printf("|               [4] Excluir Tarefa                  |\n");
    printf("|               [5] Relatório de Tarefas            |\n");
    printf("|               [0] Sair                            |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    return op;
}

void add_task(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                              Cadastrar Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    if (register_task())
    {
        show_sucess("| Tarefa cadastrada com sucesso!\n");
    }
    else
    {
        show_error("| [ERRO]: Erro ao cadastrar!\n");
    }

    enter();
}

Task *struct_task(void)
{
    printf("|\tInforme o ID: ");
    char id[4];
    scanf("%4s", id);
    Task *task = load_task(id);

    return task;
}

void search_task(void)
{
    limpa_buffer();
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Exibir Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    Task *task = struct_task();

    if (task != NULL)
    {
        display_data_task(task);
    }
    else
        show_error("Tarefa não encontrada");

    enter();
}

void change_task(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Editar Tarefa                                                            |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    Task *task = struct_task();

    if (task != NULL)
    {
        display_data_task(task);
        edit_task(task);
    }
    else
        show_error("Tarefa não encontrada");

    enter();
}

void delete_task(void)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Fechar Tarefa                                                                 |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    enter();
    Task *task = struct_task();

    if (task == NULL)
        show_error("Tarefa não encontrada");
    else if (task->status == '0')
        show_error("Tarefa já fechada");
    else
    {
        task->status = '0';
        update_task(task);
        show_sucess("Tarefa fechada com sucesso!");
    }

    enter();
}

void show_all_tasks(void)
{
    limpar_tela();
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                              Relatorio de Tarefa                                                              |\n");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");

    char opc;

    do
    {
        printf("|[1] -> Tarefas não concluidas\n");
        printf("|[2] -> Tarefas concluídas\n");
        printf("|[3] -> Tarefas por usuários\n");
        printf("|[4] -> Tarefas com times\n");
        printf("|[5] -> Todas as tarefas\n");
        printf("|[6] -> Tarefas em atraso\n");
        printf("|[0] -> Voltar\n");
        scanf(" %c", &opc);

        switch (opc)
        {
        case '1':
            show_tasks('1', "status");
            break;
        case '2':
            show_tasks('0', "status");
            break;
        case '3':
            show_tasks('1', "users");
            break;
        case '4':
            show_tasks('1', "teams");
            break;
        case '5':
            show_tasks('\0', "all");
            break;
        case '6':
            show_tasks('1', "pending");
            break;
        case '0':
            return;
        default:
            show_error("Opção inválida!");
        }

    } while (opc != '0');

    enter();
}

void display_data_task(Task *task)
{
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|                                                                 Dados do Tarefa                                                               |\n");
    printf("| \033[1mID:\033[0m %s\n", task->id);
    if (strstr(task->responsible, "T"))
        printf("|\033[1m\tTime responsável:\033[0m %s\n", task->responsible);
    else
        printf("|\033[1m\tUsuario responsável:\033[0m %s\n", task->responsible);
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
    printf("|\033[1m\tTarefa:\033[m %s\n", task->title);
    printf("|\033[1m\tDescrição:\033[m %s\n", task->description);
    printf("|\033[1m\tData:\033[m %s\n", task->date);
    printf("|\033[1m\tPrioridade:\033[m %s\n", task->priority == 'A' ? "Alta" : task->type == 'M' ? "Média"
                                                                                                  : "Baixa");
    printf("|\033[1m\tTipo:\033[m %s\n", task->type == 'E' ? "Evento" : task->type == 'R' ? "Reunião"
                                                                                          : "Projeto");
    printf("|\033[1m\tStatus:\033[0m %s\n", task->status == '0' ? "Fechada" : "Ativa");
    printf("|+---------------------------------------------------------------------+-----------------------------------------------------------------------+|\n");
}
