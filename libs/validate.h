#ifndef VALIDATE_H
#define VALIDATE_H

int valid_phone(char *telephone);
int length_prompt(char *prompt, int maxLength, int minLength);
int valid_name(char *name);
int valid_description(char *description);
int validation_cpf(char cpf[]);
int cpf_unique_user(const char *cpf, const char *file);
int bissexto(char year[]);
int dia_mes(int mês);
int validar_data(char day[], char month[], char year[]);
int validar_tempo(char tempo[]);
int validar_data_se_fevereiro(char month[], char year[], char day[]);
int validar_data_alternativo(char day[], char month[]);
int validar_data_february(char month[]);

#endif