#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CompromissosController.h"
#include "CompromissosView.h"
#include "CompromissosModel.h"

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/styles.h"
#include "../libs/date.h"
#include "../libs/reads.h"


char* responsible(void){
    printf("|\tCompromisso destinado a:\n");
    printf("|\t[1] Usuário\n\t[2] Equipe\n");

    char *choice = (char*)malloc(4 * sizeof(char));
    char op;

    scanf(" %c", &op);

    switch (op) {
        case '1':
            printf("ID ou CPF do usuário: \n");
            scanf("%4s", choice);
            if(user_exists(choice)) return choice;
            break;
        case '2':
            printf("ID do time: \n");
            scanf("%4s", choice);
            return choice;
            break;
        default:
            show_error("Opção inválida.");
            break;
    }

    return NULL;
}


int register_compromise(void){
    limpa_buffer();
    int year = year_now();

    Compromisers compromise = {0};

    char *id = responsible();
    strcpy(compromise.responsible, id);

    limpa_buffer();
    printf("|\tTítulo: ");
    char *title = read_string();
    strcpy(compromise.title, title);

    printf("|\tDescrição: ");
    char *description = read_string();
    strcpy(compromise.description, description);

    limpa_buffer();
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    printf("\tData: \n");
    read_date(day, month);
    snprintf(compromise.date, 12, "%s/%s/%d", day, month, year);

    limpa_buffer();
    printf("\tTipo de compromisso: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
    char type = read_generic_123("type");
    compromise.type = type;

    printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
    char priority = read_generic_123("priority");
    compromise.priority = priority;

    compromise.status = '1';

    int result = insert_compromise(&compromise);

    return result;
}

void edit_compromise(Compromisers *compromise){
    limpa_buffer();
    
    int year = year_now();
    char opc;
    int result = FALSE;

    do {
        printf("Opção de edição:\n");
        printf("[1] Responsável\n");
        printf("[2] Título\n");
        printf("[3] Descrição\n");
        printf("[4] Data\n");
        printf("[5] Prioridade\n");
        printf("[6] Tipo\n");
        printf("[0] Sair\n");
        scanf(" %c", &opc);

        switch (opc) {
            case '1':
                limpa_buffer();
                char *id = responsible();
                strcpy(compromise->responsible, id);
                result = update_compromise(compromise);
                result ? show_sucess("Responsável editado com sucesso!") : show_error ("Erro ao editar o responsável");
            case '2':
                limpa_buffer();
                printf("|\tTítulo: ");
                char *title = read_string();
                strcpy(compromise->title, title);
                result = update_compromise(compromise);
                result ? show_sucess("Título editado com sucesso!") : show_error ("Erro ao editar o titulo");
            case '3':
                limpa_buffer();
                printf("|\tDescrição: ");
                char *description = read_string();
                strcpy(compromise->description, description);
                result = update_compromise(compromise);
                result ? show_sucess("Descrição editada com sucesso!") : show_error ("Erro ao editar a descrição");
                break;
            case '4':
                limpa_buffer();
                char day[MAX_DAY_LENGHT];
                char month[MAX_MONTH_LENGHT];
                printf("\tData: \n");
                read_date(day, month);
                snprintf(compromise->date, 12, "%s/%s/%d", day, month, year);
                result = update_compromise(compromise);
                result ? show_sucess("Data editada com sucesso!") : show_error ("Erro ao editar a data");
                break;
            case '5':
                limpa_buffer();
                printf("\tNível de urgência: \n\t[1]Alta \n\t[2]Média \n\t[3]Baixa\n");
                char priority = read_generic_123("priority");
                compromise->priority = priority;
                result = update_compromise(compromise);
                result ? show_sucess("Prioridade editada com sucesso!") : show_error ("Erro ao editar a prioridade");
                break;
            case '6':
                limpa_buffer();
                printf("\tTipo de compromisso: \n\t[1]Evento \n\t[2]Reunião \n\t[3]Projeto\n");
                char type = read_generic_123("type");
                compromise->type = type;
                result = update_compromise(compromise);
                result ? show_sucess("Tipo editado com sucesso!") : show_error ("Erro ao editar o tipo");
                break;
            case '0':
                break;
            default:
                show_error("Opção inválida.");
                break;
        }

    } while (opc != '0');
}