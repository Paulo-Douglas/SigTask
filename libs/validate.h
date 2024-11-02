#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int length_prompt(char *prompt, int maxLength, int minLength);
int valid_name(char *name);
int valid_description(char *description);
int validation_cpf(char cpf[]);
int bissexto(char year[]);
int dia_mes(int mês);
int validar_data(char day[], char month[], char year[]);

#endif