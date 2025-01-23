#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int validate_name(char *name);
int validate_description(char *description);
int validate_cpf(char cpf[]);
int length_prompt(char *prompt, int minLength);
int user_exists(const char *cpf, const int id);
int team_exists(const int id);

#endif