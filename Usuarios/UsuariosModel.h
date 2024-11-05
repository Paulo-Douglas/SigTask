#ifndef USUARIOSMODEL_H
#define USUARIOSMODEL_H

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char phone[MAX_TEL_LENGTH];
} User;

int save_user(char *name, char *cpf, char *phone);

#endif // USUARIOSMODEL_H