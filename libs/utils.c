#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#include "utils.h"
#include "../Tarefas/TarefasController.h"

void limpa_buffer(void)
{
    int b;
    while ((b = getchar()) != '\n' && b != EOF);
}

void enter(void)
{
    printf("| Tecle <ENTER> para continuar...");
    limpa_buffer();
}

void limpar_tela(void)
{
    system("clear || cls");
}

void create_path(const char *name_path)
{
    struct stat path = {0};
    if (stat(name_path, &path) == -1)
    {
        mkdir("data", 0700);
    }
}

int year_now(void)
{
    // OpenAI. (2023). ChatGPT (modelo GPT-4)

    time_t t = time(NULL);         // Tempo em segundos
    struct tm tm = *localtime(&t); // Tempo local
    int year = tm.tm_year + 1900;  // Soma 1900 para obter o ano completo
    return year;
}

void date_now(char *date)
{
    time_t time_now = time(NULL);
    struct tm *tm_info = localtime(&time_now);
    strftime(date, 11, "%d/%m/%Y", tm_info);
}

int check_dates(const char *date1)
{

    char date2[11];
    date_now(date2);

    struct tm tm1 = {0}; // Inicialização
    struct tm tm2 = {0};
    time_t t1, t2; // Datas em segundos

    sscanf(date1, "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
    sscanf(date2, "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);

    // Ajustes
    tm1.tm_year -= 1900;
    tm2.tm_year -= 1900;
    tm1.tm_mon--;
    tm2.tm_mon--;

    t1 = mktime(&tm1); // Conversão
    t2 = mktime(&tm2);

    double diff = difftime(t1, t2); // Diferença em segundos

    if (diff > 0)
        return TRUE;
    else
        return FALSE;
}

int compare_dates(const char *date1, const char *date2)
{

    struct tm tm1 = {0};
    struct tm tm2 = {0};
    time_t t1, t2;

    sscanf(date1, "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
    sscanf(date2, "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);

    tm1.tm_year -= 1900;
    tm2.tm_year -= 1900;
    tm1.tm_mon--;
    tm2.tm_mon--;

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);

    double diff = difftime(t1, t2);

    if (diff > 0)
        return 1;
    else if (diff < 0)
        return -1;
    else
        return 0;
}