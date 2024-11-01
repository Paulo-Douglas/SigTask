#include "../libs/utils.h"
#include "../libs/validate.h"
#include "UsuariosView.h"
#include "stdio.h"

void processar_cadastro(void){
    char name[MAX_NAME_LENGTH];
    char phone[MAX_TEL_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    do {
        cadastrar_usuarios(name, phone, cpf);

        if (!valid_phone(phone)) {
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            getchar();
        } 
    } while(valid_phone(phone) == FALSE);
    

    show_sucess("Usuário cadastrado com sucesso");
}