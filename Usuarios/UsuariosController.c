#include "../libs/utils.h"
#include "../libs/validate.h"
#include "UsuariosView.h"
#include "stdio.h"

void processar_cadastro(void){
    char name[MAX_NAME];
    char phone[MAX_TEL];
    char cpf[MAX_CPF];

    do {
        cadastrar_usuarios(name, phone, cpf);

        if (!valid_phone(phone)) {
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            getchar();
        } 
    } while(valid_phone(phone) == FALSE);
    

    show_sucess("Usuário cadastrado com sucesso");
}