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
    char turn[MAX_TURN_LENGHT];
    char priority[MAX_PRIORITY_LENGHT]; // tenho que achar uma solução para isso
    char status[MAX_STATUS_LENGHT];
    char data[MAX_CALENDAR_LENGHT];  
} Tasks;

int save_task(char *cpf, char *title, char *description, char *day, char *month, 
<<<<<<< HEAD
              char *year, char *turn, char *priority);
=======
              char *year, char *turn, char *priority, char *status);
>>>>>>> 79912318ecc00b6c6fa310a6bf7d657ee4a7776d
int load_task(const char *cpf);

#endif