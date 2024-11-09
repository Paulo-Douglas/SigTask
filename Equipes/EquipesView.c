#include <stdio.h>

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
    printf("|               [3] Editar Equipe                  |\n");
    printf("|               [4] Excluir Equipe                 |\n");
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

    if (register_academic_team()){
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

    if(register_business_team()){
        show_sucess("Sucesso ao registrar a equipe!");
    } else {
        show_error("[ERROR] Falha ao cadastrar a equipe!");
    }
    limpa_buffer();
}

void exibir_equipe(void) { 
    limpar_tela();
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Exibir equipe                 |\n");
    printf("--------------------------------------------------\n");
    if(!search_team()){
        show_error("Equipe inexistente; <ENTER> para continuar\n");
    } else {
        printf("Tecle <ENTER> para continuar...");
    }
    getchar();
}

void editar_equipe(void) { 
    limpar_tela();
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Editar equipe                 |\n");
    printf("--------------------------------------------------\n");
}

void excluir_equipe(void) { 
    limpar_tela();
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("|                  Excluir equipe                |\n");
    printf("--------------------------------------------------\n");
}


void alterar_equipe_academica(void){
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                           Alterar dados do acadêmico                                                          |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  ID  |   1   ->      Nome da instituição         |       2   ->        Nome da equipe            |      3   ->     Descrição da equipe        |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

}

void alterar_equipe_empresarial(void){
    limpar_tela();
    printf("\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                          Alterar dados do empresarial                                                         |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  CNPJ        |   1   ->     Nome da empresa          |    2   ->       Nome da equipe         |     3   ->     Descrição da equipe            |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

}