#ifndef UTILS_H
#define UTILS_H

// Tamanhos de cadastros
#define VARCHAR50 50
#define VARCHAR10 10

// Campos de cadastro no arquivo
#define FIELD_CPF "\"Cpf\":"
#define FIELD_DATA "\"Data\":"
#define FIELD_TURN "\"Turno\":"
#define FIELD_NAME "\"Nome\":"
#define FIELD_INSTITUICAO "\"Instituição\":"
#define FIELD_TEAM "\"Time\":"
#define FIELD_USER "\"Usuarios\":"
#define FIELD_PHONE "\"Telefone\":"
#define FIELD_TITLE "\"Titulo\":"
#define FIELD_TYPE "\"Tipo\":" 
#define FIELD_DESCRIPTION "\"Descricao\":"
#define FIELD_DATE "\"Data\":"
#define FIELD_PRIORITY "\"Prioridade\":"
#define FIELD_STATUS "\"Status\":"
#define FIELD_TIME "\"Horario\":"


// Valores booleanos
#define TRUE 1
#define FALSE 0

// Valores de tamanho de variaveis
#define MIN_DESCRIPTION_LENGTH 10
#define MAX_DAY_LENGHT 3
#define MAX_MONTH_LENGHT 3
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

char* extract_value(char **source, const char *start_delim, const char *end_delim);

#endif