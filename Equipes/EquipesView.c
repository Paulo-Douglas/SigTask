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
    printf("|               [3] Adicionar membro a Equipe      |\n");
    printf("|               [4] Remover membro da Equipe       |\n");
    printf("|               [5] Excluir Equipe                 |\n");
    printf("|               [6] Editar Equipe                  |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op);
    getchar();  
    return op;
}


void register_team_academic(void){
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


void modify_team_data_academic(void){
    show_header("Editar dados");
    enter();
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
    if (team == NULL) show_error("Equipe não encontrada");
    if (team->status == '0') show_error("Equipe não disponível");
    else{
        view_team(team);
    }

    limpa_buffer();
    enter();
}


void add_user_to_team(void) { 
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                Adicionar membro                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void remove_user_from_team(void) { 
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                Remover membro                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void excluir_equipe(void) { 
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Excluir equipe                                                                  |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
}


void view_team(const Team *teams){
    show_header("Dados do time");
    printf("\033[1m|ID:\033[m %s\n", teams->id);
    printf("\033[1m|Usuários:\033[m %s\n", teams->users);
    printf("\033[1m|Nome da instituição:\033[m %s\n", teams->name);
    printf("\033[1m|Descrição:\033[m %s\n", teams->description);
    printf("\033[1m|Status:\033[m %s\n", teams->status == '1' ? "Ativo" : "Invativo");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    getchar();
}


