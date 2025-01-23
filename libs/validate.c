#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>
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
    const char *standardDescription = "^[A-Za-zÇçÀÁÂÉÊÍÓÔÚàáâéêíóôú.,!?-]+( [A-Za-zÇçÀÁÂÉÊÍÓÔÚàáâéêíóôú.,!?-]+)*$";
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

int check_equal_numbers(const char* cpf, int size) {
    char ref_digit = '\0';

    for (int i = 0; i < size; i++) {
        if (isdigit(cpf[i])) {  // Verifica se é um dígito numérico
            if (ref_digit == '\0') {
                ref_digit = cpf[i];  // Armazena o primeiro dígito encontrado
            } else if (cpf[i] != ref_digit) {
                return 0;  // Retorna 0 se encontrar um dígito diferente
            }
        }
    }

    return 1;  // Retorna 1 se todos os dígitos forem iguais
}

int validate_cpf(char cpf[])
{
    int calcule_one_dig = 0;
    int calcule_second_dig = 0;
    int x = 14;
    
    if (check_equal_numbers(cpf, x))
        return 0;

    calcule_one_dig = (cpf[0] - '0') * 10 + (cpf[1] - '0') * 9 +
                      (cpf[2] - '0') * 8 + (cpf[4] - '0') * 7 + // aqui faço pulo de indices para dar espaço
                      (cpf[5] - '0') * 6 + (cpf[6] - '0') * 5 + // para os indices 3, 7, 11 (para pontuação)
                      (cpf[8] - '0') * 4 + (cpf[9] - '0') * 3 +
                      (cpf[10] - '0') * 2;
    calcule_one_dig %= 11;
    calcule_one_dig = (calcule_one_dig < 2) ? 0 : 11 - calcule_one_dig;

    if(cpf[12] - '0' != calcule_one_dig){
        return 0; 
    }
    calcule_second_dig = (cpf[0] - '0') * 11 + (cpf[1] - '0') * 10 +
                         (cpf[2] - '0') * 9 + (cpf[4] - '0') * 8 +
                         (cpf[5] - '0') * 7 + (cpf[6] - '0') * 6 +
                         (cpf[8] - '0') * 5 + (cpf[9] - '0') * 4 +
                         (cpf[10] - '0') * 3 + (cpf[12] - '0') * 2;

    calcule_second_dig %= 11;
    calcule_second_dig = (calcule_second_dig < 2) ? 0 : 11 - calcule_second_dig;
    
    if(cpf[13] - '0' != calcule_second_dig){
        return 0; 
    }

    if ((strlen(cpf) >= x) && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int user_exists(const char *cpf, const int id)
{
    int exists = FALSE;

    FILE *fp = fopen("data/users.dat", "rb");
    if (fp == NULL)
    {
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
        if (cpf != NULL && cpf[0] != '\0' && strcmp(user->cpf, cpf) == 0 && user->status == '1')
        {
            exists = TRUE;
            break;
        }
        else if (id != 0 && user->id == id && user->status == '1')
        {
            exists = TRUE;
            break;
        }
    }

    fclose(fp);
    free(user);

    return exists;
}

int team_exists(const int id)
{
    int exists = FALSE;

    FILE *fp = fopen("data/teams.dat", "rb");
    if (fp == NULL)
        return exists;

    Team *team = (Team *)malloc(sizeof(Team));
    while (fread(team, sizeof(Team), 1, fp) && !exists)
    {
        if (team->id == id && (team->status == '1'))
        {
            exists = TRUE;
        }
    }
    fclose(fp);
    free(team);
    return exists;
}
