#include <stdio.h>
#include <string.h>

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

void cadastro_tipo_de_equipe(void) { 
    char op;
    limpar_tela();
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("|                 [1] Cadastro de equipe acadêmica                |\n");
    printf("|                 [2] Cadastro de equipe empresarial              |\n");
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op); 
    getchar(); // para evitar problemas com o enter no buffer

    switch(op) {
        case '1':
            cadastrar_equipe_academica();
            break;
        case '2':
            cadastrar_equipe_empresarial();
            break;
        default:
            printf("Opção inválida. Voltando ao menu principal...\n");
            break;
    }
}

void cadastrar_equipe_academica(void){
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Cadastro de equipe acadêmica                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  ID  |        Nome da instituição          |               Nome da equipe               |             Descrição da equipe                     |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    if (insert_team_academic()){
        show_sucess("Sucesso ao registrar a equipe!");
    } else {
        show_error("[ERROR] Falha ao cadastrar a equipe!");
    }
    limpa_buffer();
}

void cadastrar_equipe_empresarial(void){
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Cadastro de equipe empresarial                                                     |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  CNPJ        |        Nome da empresa             |               Nome da equipe               |               Descrição da equipe            |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

    if(insert_team_business()){
        show_sucess("Sucesso ao registrar a equipe!");
    } else {
        show_error("[ERROR] Falha ao cadastrar a equipe!");
    }
    limpa_buffer();
}

void exibir_equipe(void) { 
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                               Exibir equipe                                                                   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    if(!search_team()){
        show_error("Equipe inexistente; <ENTER> para continuar\n");
    } else {
        printf("Tecle <ENTER> para continuar...");
    }
    getchar();
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


void alterar_tipo_de_equipe(void) { 
    char op;
    limpar_tela();
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("|                 [1] Alterar dados de equipe acadêmica           |\n");
    printf("|                 [2] Alterar dados de equipe empresarial         |\n");
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &op); 
    getchar(); // para evitar problemas com o enter no buffer

    switch(op) {
        case '1':
            modify_team_data_academic();
            break;
        case '2':
            modify_team_data_business();
            break;
        default:
            printf("Opção inválida. Voltando ao menu principal...\n");
            break;
    }
}


void team_data_academic(const Team *teams){
    show_header("Dados do time");
    printf("\033[1m|ID:\033[m %s\n", teams->id);
    printf("\033[1m|Usuários:\033[m %s\n", teams->usuarios);
    printf("\033[1m|Nome da instituição:\033[m %s\n", teams->team_name_especific);
    printf("\033[1m|Nome da equipe:\033[m %s\n", teams->team_name);
    printf("\033[1m|Descrição:\033[m %s\n", teams->description);
    printf("\033[1m|Status:\033[m %s\n", strcmp(teams->status, "0") ? "Ativo" : "Invativo");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}

void team_data_business(const Team *teams){
    show_header("Dados do time");
    printf("\033[1m|CNPJ:\033[m %s\n", teams->id);
    printf("\033[1m|Usuários:\033[m %s\n", teams->usuarios);
    printf("\033[1m|Nome da empresa:\033[m %s\n", teams->team_name_especific);
    printf("\033[1m|Nome da equipe:\033[m %s\n", teams->team_name);
    printf("\033[1m|Descrição:\033[m %s\n", teams->description);
    printf("\033[1m|Status:\033[m %s\n", strcmp(teams->status, "0") ? "Ativo" : "Invativo");
    printf("|-------------------------------------------------------------------------------------------------------|\n");
}

void modify_team_data_academic(void){
    show_header("Editar dados");
    printf("|\tID:\t");
    char *id = read_id();
    Team teams = load_teams_academic(id);

    if (teams.id != NULL){
        team_data_academic(&teams);
        int result = update_team_academic(&teams);
            show_sucess("| Dados alterados com sucesso!\n");
        }else {
            show_error("| [ERRO]: Erro ao alterar!\n");
        }
    }

    enter();

}

void modify_team_data_business(void){
    show_header("Editar dados");
    printf("|\tID:\t");
    char *id = read_id();
    Team teams = load_teams_business(id);

    if (teams.id != NULL){
        team_data_business(&teams);
        int result = update_team_business(&teams);
        if (result){
            show_sucess("| Dados alterados com sucesso!\n");
        }else {
            show_error("| [ERRO]: Erro ao alterar!\n");
        }
    }

    enter();

}