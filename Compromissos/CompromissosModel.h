#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

typedef struct
{
    char cpf[MAX_CPF_LENGTH];
    char title[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char day_start[MAX_DAY_LENGHT];
    char month_start[MAX_MONTH_LENGHT];
    int year_start;
    char day_end[MAX_DAY_LENGHT];
    char month_end[MAX_MONTH_LENGHT];
    int year_end;
    char time[MAX_TIME_LENGHT];
    char priority[MAX_PRIORITY_LENGHT]; // tenho que achar uma solução para isso
    char data_start[MAX_CALENDAR_LENGHT];
    char data_end[MAX_CALENDAR_LENGHT];
} Compromisers;

int save_compromiser(char *cpf, char *title, char *description, char *day_start, char *month_start,
                     int year_start, char *day_end, char *month_end, int year_end, char *time, char *priority);

int load_compromiser(const char *cpf);

#endif