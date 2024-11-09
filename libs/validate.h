#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int length_prompt(char *prompt, int maxLength, int minLength);
int validate_name(char *name);
int validate_description(char *description);
int validate_cpf(char cpf[]);
int cpf_unique_user(const char *cpf, const char *file);
int validate_month(char month[]);
int bissexto(char year[]);
int day_month(int mês);
int validate_date(char day[], char month[], char year[]);
int validate_time(char tempo[]);
int valide_month_for_february(char month[]);
int valited_day_moth(char day[], char month[]);

#endif