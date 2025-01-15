#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "utils.h"
#include "validate.h"

#include "../Usuarios/UsuariosController.h"
#include "../Equipes/EquipesController.h"

int valid_phone(char *telephone)
{
    regex_t phoneRegex;

    const char *standardPhone = "^[0-9]{2} [0-9]{1} [0-9]{8}$";
    int reti;

    reti = regcomp(&phoneRegex, standardPhone, REG_EXTENDED);
    if (reti)
        return FALSE;

    reti = regexec(&phoneRegex, telephone, 0, NULL, 0);
    regfree(&phoneRegex);

    return reti == 0;
}

int validate_name(char *name)
{
    regex_t nameRegex;

    const char *standardName = "^[A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú]+( [A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú]+)*$";
    int reti;

    reti = regcomp(&nameRegex, standardName, REG_EXTENDED);
    if (reti)
        return FALSE;

    reti = regexec(&nameRegex, name, 0, NULL, 0);
    regfree(&nameRegex);

    return reti == 0;
}

int length_prompt(char *prompt, int minLength)
{
    return strlen(prompt) < minLength;
}

int validate_description(char *description)
{
    if (length_prompt(description, MIN_DESCRIPTION_LENGTH))
        return 0;

    regex_t descriptionRegex;
    const char *standardDescription = "^[A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú.,!?-]+( [A-Za-zÇçÁÂÉÊÍÓÔÚáâéêíóôú.,!?-]+)*$";
    int reti;

    reti = regcomp(&descriptionRegex, standardDescription, REG_EXTENDED);
    if (reti)
    {
        return FALSE;
    }

    reti = regexec(&descriptionRegex, description, 0, NULL, 0);
    regfree(&descriptionRegex);

    return reti == 0;
}

int validate_cpf(char cpf[])
{
    int calcule_one_dig = 0;
    int calcule_second_dig = 0;
    int x = 14;

    calcule_one_dig = (cpf[0] - '0') * 10 + (cpf[1] - '0') * 9 +
                      (cpf[2] - '0') * 8 + (cpf[4] - '0') * 7 + // aqui faço pulo de indices para dar espaço
                      (cpf[5] - '0') * 6 + (cpf[6] - '0') * 5 + // para os indices 3, 7, 11 (para pontuação)
                      (cpf[8] - '0') * 4 + (cpf[9] - '0') * 3 +
                      (cpf[10] - '0') * 2;

    calcule_second_dig = (cpf[0] - '0') * 11 + (cpf[1] - '0') * 10 +
                         (cpf[2] - '0') * 9 + (cpf[4] - '0') * 8 +
                         (cpf[5] - '0') * 7 + (cpf[6] - '0') * 6 +
                         (cpf[8] - '0') * 5 + (cpf[9] - '0') * 4 +
                         (cpf[10] - '0') * 3 + (cpf[12] - '0') * 2;

    if (((calcule_one_dig * 10) % 11 == (cpf[12] - '0')) && (calcule_second_dig * 10) % 11 == (cpf[13] - '0') && (strlen(cpf) >= x) && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int user_exists(const char *key)
{
    int exists = FALSE;

    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return exists;
    }

    User *user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(fp);
        return exists;
    }

    while (fread(user, sizeof(User), 1, fp))
    {
        printf("ID: %s, CPF: %s\n", user->id, user->cpf);

        if ((strcmp(user->cpf, key) == 0) && (strlen(key) > 5))
        {
            exists = TRUE;
            break;
        }
        else if ((strcmp(user->id, key) == 0) && (user->status == '1'))
        {
            exists = TRUE;
            break;
        }
    }

    fclose(fp);
    free(user);

    return exists;
}

int team_exists(const char *key)
{
    int exists = FALSE;

    FILE *fp = fopen("data/teams.dat", "rb");
    if (fp == NULL)
        return exists;

    Team *team = (Team *)malloc(sizeof(Team));
    while (fread(team, sizeof(Team), 1, fp) && !exists)
    {
        if ((strcmp(team->id, key) == 0) && (team->status == '1'))
        {
            exists = TRUE;
        }
    }
    fclose(fp);
    free(team);
    return exists;
}
