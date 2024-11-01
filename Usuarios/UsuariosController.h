#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

typedef struct
{
    char nome[50];
    char cpf[12];
    char telefone[15];
}User;

void processar_cadastro(void);


#endif // USUARIOSCONTROLLER_H