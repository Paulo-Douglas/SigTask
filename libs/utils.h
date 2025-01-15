#ifndef UTILS_H
#define UTILS_H

// Valores booleanos
#define TRUE 1
#define FALSE 0

// Valores de tamanho de variaveis
#define MIN_DESCRIPTION_LENGTH 10
#define MAX_DAY_LENGHT 3
#define MAX_MONTH_LENGHT 3
#define MAX_LINE_LENGTH 250

typedef struct
{
  char **file;
  int line_count;
} File;

typedef enum
{
  DESATIVADO,
  ATIVADO
} Status;

void limpa_buffer(void);
void limpar_tela(void);
void create_path(const char *name_path);
void enter(void);

int check_dates(const char *date1);
int year_now(void);
void date_now(char *date);

#endif