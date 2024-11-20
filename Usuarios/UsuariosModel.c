#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libs/utils.h"
#include "../libs/validate.h"
#include "../libs/reads.h"

#include "UsuariosModel.h"


int insert_to_user(User *users, const char* file_name){
    FILE *fp = fopen(file_name, "a");
    if(fp == NULL) return FALSE;

    fprintf(fp, "%s:%-229s;%s\n", users->cpf, users->name, users->phone);
    fclose(fp);
    return TRUE;
}


int load_user(const char *cpf){

               // aqui faz uma tela

    FILE *arquivo_usuarios = fopen("usuarios.txt", "rb+");
    if (arquivo_usuarios == NULL){
        printf("Não há usuários cadastrados para editar ");
        printf("Pressione ENTER para continuar ");
        getchar();
    }


    if (!cpf_unique_user(cpf, "usuarios.txt")){
        printf("CPF não encontrado! ");
        return FALSE;
    }
    else{
        User user;

        FILE *fp = fopen("data/users.txt", "r");
        if(fp == NULL) return FALSE;
        const char *data[4];
        data[3] = NULL;
        int found = FALSE;
        while(fread(&user, sizeof(User), 1, arquivo_usuarios)){
            if(strcmp(user.cpf, cpf) == 0){
                int op;
                printf("\n");
                printf("----------------------------------------------------\n");
                printf("|                    Alterar dados                 |\n");
                printf("----------------------------------------------------\n");
                printf("|               [1] Nome                           |\n");
                printf("|               [2] Telefone                       |\n");
                printf("|               [3] Todos os dados                 |\n");
                printf("|               [0] Sair                           |\n");
                printf("----------------------------------------------------\n");
                printf("Escolha a opção desejada: ");
                scanf(" %d", &op);

                switch (op)
                {
                case 1:
                    printf("Informe o nome: ");
                    char *name = read_string();
                    data[1] = name;   
                    break;
                case 2:
                    printf("Informe o telefone: ");
                    char *phone = read_phone();
                    data[2] = phone;  
                    break;
                case 3:
                    printf("Informe o nome: ");
                    char *name1 = read_string();
                    data[1] = name1; 
                    printf("Informe o telefone: ");
                    char *phone2 = read_phone();
                    data[2] = phone2;    

                default:{
                    printf("Opção inválida");
                }
                
                fseek(arquivo_usuarios, -sizeof(User), SEEK_CUR);
                fwrite(&user , sizeof(User), 1, arquivo_usuarios);
                int result = save_file(data, "data/users.txt");

                free(name);
                free(phone);
                return result;

                fclose(fp);

                return found;
                
            }
        }
    }
    }
    return TRUE;
}


