#include <string.h>
#include <stdio.h>
#include "../libs/utils.h"
#include "../libs/validate.h"
#include "UsuariosView.h"
#include "UsuariosController.h"

void processar_cadastro(void){
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];    

    show_sucess("Usuário cadastrado com sucesso");
}

void read_phone(void){
    char phone[MAX_TEL_LENGTH];
    
    do{
        fgets(phone, MAX_TEL_LENGTH, stdin);
        phone[strcspn(phone, "\n")] = 0;
        printf("\n");

        if(!valid_phone(phone)){
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
        }

    } while(valid_phone(phone) == FALSE);
}