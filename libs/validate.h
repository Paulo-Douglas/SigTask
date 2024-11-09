#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int length_prompt(char *prompt, int maxLength, int minLength);
int valid_name(char *name);
int valid_description(char *description);
int validation_cpf(char cpf[]);
int cpf_unique_user(const char *cpf, const char *file);
int validate_month(char month[]);
int bissexto(char year[]);
int dia_mes(int mês);
int validar_data(char day[], char month[], char year[]);
int validar_tempo(char tempo[]);
int valide_month_for_february(char month[]);
int valited_day_moth(char day[], char month[]);

#endif