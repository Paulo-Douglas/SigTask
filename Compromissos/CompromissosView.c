#include <stdio.h>

#include "CompromissosController.h"
#include "CompromissosView.h"

#include "../libs/utils.h"
#include "../libs/reads.h"

#include "../Usuarios/UsuariosView.h"



/*************  ✨ Codeium Command ⭐  *************/
/******  a003a083-17b6-4b8a-a6d9-f8508e158f7b  *******/char menu_compromissos(void) {
    char op;
    limpar_tela();
    printf("----------------------------------------------------\n");
    printf("|                     Compromissos                 |\n");
    printf("----------------------------------------------------\n");
    printf("|               [1] Cadastrar Compromisso          |\n");
    printf("|               [2] Exibir Compromisso             |\n");
    printf("|               [3] Editar Compromisso             |\n");
    printf("|               [4] Excluir Compromisso            |\n");
    printf("|               [0] Sair                           |\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_compromissos(void) {
    limpar_tela();
    printf("-------------------------------------------------------------------------------------\n");
    printf("|                                  Cadastro Tarefas                                 |\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("|  Título  |  Descrição  |  Data de início |  Data de fim |  Horário  | Prioridade  |\n");
    printf("-------------------------------------------------------------------------------------\n");

    if (register_compromise()){
        show_sucess("Compromisso cadastrada com sucesso! <ENTER> para continuar\n");
    } else {
        show_error("[ERRO]: Erro ao cadastrar \n<ENTER> para continuar\n");
    }
    limpa_buffer();
    }


void exibir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Exibir Compromissos            | \n");
    printf("--------------------------------------------------\n");

    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    if(!search_compromiser_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_compromissos();
        if(!upload_data_compromiser(cpf)){
            show_error("Erro ao carregar as tarefas do usuário!\n");
        }
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 
}    

void editar_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                 Editar Compromissos            |\n");
    printf("--------------------------------------------------\n");
    
    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    if(!search_compromiser_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        alterar_dados_compromissos();
        upload_data_compromiser(cpf);
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 

}

void excluir_compromissos(void) { 
    limpar_tela();
    printf("--------------------------------------------------\n");
    printf("|                Excluir Compromissos            |\n");
    printf("--------------------------------------------------\n");
    
    char cpf[MAX_CPF_LENGTH];
    printf("Informe seu CPF: ");
    read_cpf(cpf);

    if(!search_compromiser_to_user(cpf)){
        show_error("CPF não encontrado!\n");
    } else {
        dados_compromissos();
        if(!upload_data_compromiser(cpf)){
            show_error("Erro ao carregar as tarefas do usuário!\n");
        }
    }   
    printf("Tecle <ENTER> para continuar...");
    getchar(); 
}

void dados_compromissos(void) { // será implementado as variveis de cada dado
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                            Dados do Compromisso                                                               |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  ID  |        Título        |                Descrição                |    Data de início  |    Data de fim  |    Horário   |    Prioridade   |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");  
}

void alterar_dados_compromissos(void) {
    limpar_tela();
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                          Alterar Dados do Compromisso                                                         |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|   ID   |  1   ->   Título     |        2   ->   Descrição           | 3 -> Data de início | 4 -> Data de fim|  5 -> Horário | 6 -> Prioridade |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}