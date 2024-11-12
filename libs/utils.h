#ifndef UTILS_H
#define UTILS_H

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
void exibir_menssagem(char *);
void limpar_tela(void);
void create_path(const char *name_path);

int save_file(const char *data[], char *file_name);
int add_user_to_register(File *read_file, char *anything, char *cpf);
int move_to_struct(char *anything, char *cpf, char *name_anything);
int year_now(void);

#endif