#include <stdio.h>
#include "NavigationUser.h"
#include "UsuariosController.h"
#include "UsuariosView.h"
#include "../libs/utils.h"

void navegacao_usuarios(void){
    char op;
    do{
        op = menu_usuarios();
        switch(op){
            case '1':  
                processar_cadastro();
                limpa_buffer();
                break;
            case '2':
                exibir_dados_usuario();
                limpa_buffer();
                break;
            case '3':
                alterar_dados_usuario();
                limpa_buffer();
                break;
            case '4':
                excluir_usuario();
                limpa_buffer();
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
}   