#ifndef READS_H
#define READS_H

char* read_string(void);
char* read_phone(void);
char* read_cpf(void);
char* read_description(void);
char read_generic_123(const char *dir);
void input(char **prompt);

#endif // READS_H