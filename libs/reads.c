#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "reads.h"
#include "validate.h"
#include "styles.h"
#include "utils.h"
#include "date.h"

void read_and_assign(char **field, const char *prompt, char *(*read_function)())
{
    printf("%s", prompt);
    free(*field);
    *field = read_function();
}

void input(char **prompt)
{
    char line[MAX_LINE_LENGTH];

    // Lê a entrada do usuário
    fgets(line, MAX_LINE_LENGTH, stdin);
    line[strcspn(line, "\n")] = '\0';

    // Aloca memória para a string e copia o conteúdo
    *prompt = (char *)malloc(strlen(line) + 1);
    if (*prompt == NULL)
    {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    strcpy(*prompt, line);
}

char *read_string(void)
{
    char *string;
    int is_valid;

    do
    {
        input(&string);
        is_valid = validate_name(string);

        if (!is_valid)
        {
            show_error("[ERROR] Entrada inválida!");
            printf("Tente novamente: ");
            free(string);
        }
    } while (!is_valid);

    // limpa_buffer();
    return string;
}

char *read_phone(void)
{
    char *phone;

    do
    {
        input(&phone);

        if (!valid_phone(phone))
        {
            show_error("Número de telefone inválido: (XX X XXXXXXXX)");
            printf("Tente novamente: ");
            free(phone);
        }

    } while (valid_phone(phone) == FALSE);
    // limpa_buffer();
    return phone;
}

char *read_cpf(void)
{
    char *cpf = NULL;

    do
    {
        if (cpf != NULL)
        {
            free(cpf);
        }

        input(&cpf);

        if (!validate_cpf(cpf))
        {
            show_error("CPF inválido (Formato correto: XXX.XXX.XXX-XX)");
            printf("Tente novamente: ");
        }

    } while (!validate_cpf(cpf));
    return cpf;
}

char *read_description(void)
{
    char *description;
    int is_valid;

    do
    {
        input(&description);
        is_valid = validate_description(description);

        if (!is_valid)
        {
            show_error("[ERROR] Entrada inválida!");
            printf("Tente novamente ");
            free(description);
        }
    } while (!is_valid);
    // limpa_buffer();
    return description;
}

char read_generic_123(const char *dir)
{
    char *prompt = NULL;
    do
    {
        input(&prompt);

        if (prompt == NULL || *prompt < '1' || *prompt > '3')
        {
            show_error("É preciso digitar uma opção: 1, 2 ou 3\n");
            printf("Tente novamente: ");
            free(prompt);
            prompt = NULL;
        }
    } while (prompt == NULL || *prompt < '1' || *prompt > '3');

    char result;
    if (strcmp(dir, "turn") == 0)
    {
        if (strcmp(prompt, "1") == 0)
        {
            result = MATUTINO;
        }
        else if (strcmp(prompt, "2") == 0)
        {
            result = VESPERTINO;
        }
        else
        {
            result = NOTURNO;
        }
    }
    else if (strcmp(dir, "priority") == 0)
    {
        if (strcmp(prompt, "1") == 0)
        {
            result = ALTA;
        }
        else if (strcmp(prompt, "2") == 0)
        {
            result = MEDIA;
        }
        else
        {
            result = BAIXA;
        }
    }
    else if (strcmp(dir, "type") == 0)
    {
        if (strcmp(prompt, "1") == 0)
        {
            result = EVENTO;
        }
        else if (strcmp(prompt, "2") == 0)
        {
            result = REUNIAO;
        }
        else
        {
            result = PROJETO;
        }
    }
    free(prompt);

    return result;
}
