#ifndef TAREFASMODEL_H
#define TAREFASMODEL_H

typedef struct
{
    char cpf[MAX_CPF_LENGTH];
    char title[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char day[MAX_DAY_LENGHT];
    char month[MAX_MONTH_LENGHT];
    char year[MAX_YEAR_LENGHT];
    char turn;
    char priority;  // tenho que achar uma solução para isso
    char status; 
    char data[11];  
} User;

int save_task(char *cpf, char *title, char *description, char *day, char *month, 
              char *year, char *turn, char *priority, char *status, char *data);
int load_user(const char *cpf, char *day, char *month, char *year);

#endif