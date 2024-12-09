#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int length_prompt(char *prompt, int minLength);
int validate_name(char *name);
int validate_description(char *description);
int validate_cpf(char cpf[]);
int cpf_unique_user(const char *cpf, const char *file);
int cpf_exists(const char *cpf);
int validate_time(char tempo[]);

#endif