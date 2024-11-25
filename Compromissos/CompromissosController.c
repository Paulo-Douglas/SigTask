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



int register_compromise(void){
    limpa_buffer();
    Compromisers compromise;
    int year = year_now();

    printf("|\tEquipe: ");
    compromise.team_id = read_int();

    printf("|\tTítulo: ");
    compromise.title = read_string();

    printf("|\tDescrição: ");
    compromise.description = read_description();

    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    printf("\t DATA INICIAL\n");
    read_date(day_start, month_start);
    compromise.start_date = malloc(sizeof(char) * 12);
    snprintf(compromise.start_date, 12, "%s/%s/%d", day_start, month_start, year);

    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    printf("\t DATA FINAL\n");
    read_date(day_end, month_end);
    compromise.end_date = malloc(sizeof(char) * 12);
    snprintf(compromise.end_date, 12, "%s/%s/%d", day_end, month_end, year);

    printf("|\tHorario: ");
    compromise.time = read_time();

    printf("|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ");
    compromise.priority = read_generic_123("priority");

    int result = insert_compromise(&compromise);

    return result;
}


int search_compromiser_to_user(const char* cpf){
    return cpf_unique_user(cpf, "data/users.txt");
}


int update_compromise(Compromisers *compromise, char *id) {
    limpar_tela();
    char opc;
    int result = FALSE;
    int year = year_now();

    do {
        limpar_tela();
        change_data_compromisses();
        scanf(" %c", &opc);

        switch (opc) {
            case '1':
                limpa_buffer();
                printf("|\tTítulo: ");
                compromise->title = read_string();
                result = update_date_compromise(':', compromise->title, 50, *id);
                result ? show_sucess("| Titulo alterado com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '2':
                limpa_buffer();
                printf("|\tDescrição: ");
                compromise->description = read_description();
                result = update_date_compromise('[', compromise->description, 100, *id);
                result ? show_sucess("| Descrição alterada com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '3':
                limpa_buffer();
                printf("\t DATA INICIAL\n");
                free(compromise->start_date);
                compromise->start_date = read_and_format_date(year);
                result = update_date_compromise(']', compromise->start_date, 10, *id);
                result ? show_sucess("| Data alterada com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '4':
                limpa_buffer();
                printf("\t DATA FINAL\n");
                free(compromise->end_date);
                compromise->end_date = read_and_format_date(year);
                result = update_date_compromise('-', compromise->end_date, 10, *id);
                result ? show_sucess("| Data alterada com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '5':
                limpa_buffer();
                printf("|\tHorário: ");
                compromise->time = read_time();
                result = update_date_compromise('(', compromise->time, 5, *id);
                result ? show_sucess("| Horário alterado com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '6':
                limpa_buffer();
                printf("|\tPrioridade: (1) Alta | (2) Media | (3) Baixa: ");
                compromise->priority = read_generic_123("priority");
                result = update_date_compromise(')', compromise->priority, 1, *id);
                result ? show_sucess("| Prioridade alterada com sucesso!\n") : show_error("| [ERRO]: Erro ao alterar!\n");
                getchar();
                break;

            case '7':
                limpa_buffer();
                result = update_date_compromise('#', "0", 1, *id);
                result ? show_sucess("| Tarefa fechada com sucesso!\n") : show_error("| [ERRO]: Erro ao fechar!\n");
                getchar();
                break;
            case '8':
                limpa_buffer();
                result = update_date_compromise('#', "1", 1, *id);
                result ? show_sucess("| Tarefa aberta com sucesso!\n") : show_error("| [ERRO]: Erro ao abrir!\n");
                getchar();
                break;
            case '0':
                break;
            default:
                show_error("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opc != '0');

    return result;
}


void free_strcut_compromise(Compromisers *compromise){
    if(compromise->title != NULL) free(compromise->title);
    if(compromise->description != NULL) free(compromise->description);
    if(compromise->start_date != NULL) free(compromise->start_date);
    if(compromise->end_date != NULL) free(compromise->end_date);
    if(compromise->time != NULL) free(compromise->time);
    if(compromise->priority != NULL) free(compromise->priority);
}

