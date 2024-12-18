#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/reads.h"
#include "../libs/styles.h"

#include "EquipesView.h"
#include "EquipesController.h"

char menu_equipes(void) {
    char op;
    limpar_tela();
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("|                       Equipes                    |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Equipe               |\n");
    printf("|               [2] Exibir Equipe                  |\n");
    printf("|               [3] Excluir Equipe                 |\n");
    printf("|               [4] Reativar Equipe                |\n");
    printf("|               [5] Editar Equipe                  |\n");
    printf("|               [6] Adicionar Usuário na Equipe    |\n");
    printf("|               [7] Remover Usuário na Equipe      |\n");
    printf("|               [8] Relatorio de Equipes           |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    getchar();  
    return op;
}


void add_team(void){
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Cadastro de equipe acadêmica                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    if (register_team()){
        show_sucess("Sucesso ao registrar a equipe!");
    } else {
        show_error("[ERROR] Falha ao cadastrar a equipe!");
    }
    limpa_buffer();
}


void search_team(void) {
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Exibir equipe                                                                   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    
    printf("|\t Insira o ID:    ");
    char id[4];
    scanf("%4s", id);

    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '0') {
        show_error("Equipe não disponível");
        free(team);
        limpa_buffer();
        enter();
        return;
    }

    display_data_team(team);
    free(team);

    limpa_buffer();
    enter();
}



void delete_team(void) { 
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Excluir equipe                                                                  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\t Insira o ID:    ");
    char id[4];
    scanf("%4s", id);

    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '0') {
        show_error("Equipe não disponível");
        free(team);
        limpa_buffer();
        enter();
        return;
    }

    
    team->status = '0';
    update_team(team);
    show_sucess("Equipe excluida com sucesso!");
    getchar();

    free(team);
    enter();
}

void reactive_team(void) {
    limpar_tela();
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Reabrir equipe                                                                  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\t Insira o ID:    ");
    char id[4];
    scanf("%4s", id);

    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '1') {
        show_error("Equipe já está ativa");
        free(team);
        limpa_buffer();
        enter();
        return;
    }

    
    team->status = '1';
    update_team(team);
    show_sucess("Equipe excluida com sucesso!");
    getchar();

    free(team);
    enter();
}

void edit_team(void) { 
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Editar equipe                                                                   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\t Insira o ID:    ");
    char id[4];
    scanf("%4s", id);


    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '0') {
        show_error("Equipe não disponível");
        free(team);
        limpa_buffer();
        enter();
        return;
    }

    display_data_team(team);
    modify_team_data(team);
    getchar();
    free(team);

    enter();
}

void add_user_to_team(void) {
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Adicionar usuário na equipe                                                     |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\t Insira o ID do time:    ");
    char id[4];
    scanf("%4s", id);
    getchar();

    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '0') {
        show_error("Equipe não disponível");
        free(team);
        limpa_buffer();
        enter();
        return;
    }

    display_data_team(team);
    add_user_to_team_data(team) ? show_sucess("Usuário adicionado com sucesso!") : show_error("Erro ao adicionar usuário");
    free(team);
    getchar();

    enter();
}

void remove_user_from_team(void) {
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Remover usuário da equipe                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("|\t Insira o ID do time:    ");
    char id[4];
    scanf("%4s", id);
    getchar();

    Team *team = load_team(id);
    if (team == NULL) {
        show_error("Equipe não encontrada");
        limpa_buffer();
        enter();
        return;
    }

    if (team->status == '0') {
        show_error("Equipe não disponível");
        free(team);
        limpa_buffer();
        enter();
        return; 
    }

    display_data_team(team);
    remove_user_from_team_data(team) ? show_sucess("Usuário removido com sucesso!") : show_error("Erro ao remover usuário");
    free(team);
    getchar();

    enter();

}

void show_teams(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Relatório de Equipes                                                            |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|[1] -> Listar Equipes\n");
    printf("|[2] -> Equipes ativas\n");
    printf("|[3] -> Equipes inativas\n");
    printf("|[0] -> Voltar\n");
    
    char opc;
    scanf(" %c", &opc);
    switch (opc) {
        case '1':
            report_teams('\0', "all");
            break;
        case '2':
            report_teams('1', "status");
            break;
        case '3':
            report_teams('0', "status");
            break;
        default:
            show_error("Opção inválida");
            break;
    }

    enter();
}

void display_data_team(const Team *teams){
    printf("|\t\t\033[1m-> Dados do Time\033[m \n");
    printf("\033[1m|ID:\033[m %s\n", teams->id);
    printf("\033[1m|Usuários:\033[m\n");
    for (int i = 0; i < 10; i++) {
        if (teams->users[i][0] != '\0') {
            printf("\t-> %s\n", teams->users[i]);
        }
    }
    printf("\033[1m|Nome da instituição:\033[m %s\n", teams->name);
    printf("\033[1m|Descrição:\033[m %s\n", teams->description);
    printf("\033[1m|Status:\033[m %s\n", teams->status == '1' ? "Ativo" : "Invativo");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}
