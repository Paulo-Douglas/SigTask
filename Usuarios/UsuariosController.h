#ifndef USUARIOSCONTROLLER_H
#define USUARIOSCONTROLLER_H

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char phone[MAX_TEL_LENGTH];
} User;

void save_user(char *name, char *cpf, char *phone);

#endif // USUARIOSCONTROLLER_H