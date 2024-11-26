#ifndef UTILS_H
#define UTILS_H

#define VARCHAR50 50
#define FIELD_NAME "\"Nome\":" // lenght = 54
#define FIELD_PHONE "\"Telefone\":" // lenght = 1
#define FIELD_TITLE "\"Titulo\":" // lenght = 54
#define FIELD_DESCRIPTION "\"Descricao\":" // lenght = 54
#define FIELD_DATE "\"Data\":" // lenght = 1
#define FIELD_PRIORITY "\"Prioridade\":" // 0 = Baixa, 1 = Media, 2 = Alta || length = 1
#define FIELD_STATUS "\"Status\":" // 0 = Aberto, 1 = Em andamento, 2 = Fechado || 0 = Inativo 1 = Ativo || length = 1


#define TRUE 1
#define FALSE 0
#define MAX_NAME_LENGTH 51
#define MAX_CPF_LENGTH 15
#define MAX_TEL_LENGTH 14
#define MAX_DESCRIPTION_LENGTH 51
#define MIN_DESCRIPTION_LENGTH 10
#define MAX_DAY_LENGHT 3
#define MAX_MONTH_LENGHT 3
#define MAX_YEAR_LENGHT 5
#define MAX_TIME_LENGHT 6
#define MAX_STATUS_LENGHT 2
#define MAX_PRIORITY_LENGHT 2
#define MAX_TURN_LENGHT 2
#define MAX_CALENDAR_LENGHT 11
#define MAX_LINE_LENGTH 256

typedef struct {
  char **file;
  int line_count;
} File;


void limpa_buffer(void);
void limpar_tela(void);
void create_path(const char *name_path);
void enter(void);
void delete_spaces(char *str);
int save_file(const char *data[], char *file_name);
int year_now(void);
int get_next_id(const char *name_of_file);

#endif