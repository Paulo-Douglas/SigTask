#include <stdio.h>

#include "NavigationUser.h"
#include "UsuariosView.h"

#include "../libs/utils.h"

void navegacao_usuarios(void){
    char op;
    do{
        op = menu_usuarios();
        switch(op){
            case '1':  
                cadastrar_usuarios();
                break;
            case '2':
                exibir_dados_usuario();
                break;
            case '3':
                alterar_dados_usuario();
                break;
            case '4':
                excluir_usuario();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida, por favor, digite outro valor\n");
                break;
        }
            
    } while (op != '0');
    limpa_buffer();
    limpar_tela();
}   