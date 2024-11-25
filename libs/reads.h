#ifndef READS_H
#define READS_H

char* read_string(void);
char* read_phone(void);
char* read_cpf(void);
char* read_description(void);
char* read_generic_123(const char *dir);
char* read_time(void);
char* read_and_format_date(int year);
int read_int(void);

void read_and_assign(char **field, const char *prompt, char *(*read_function)());
void input(char **prompt);

#endif // READS_H