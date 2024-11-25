#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

typedef struct
{
    char *cpf;
    char *title;
    char *description;
    char *data_start;
    char *data_end;
    char *time;
    char *priority;

} Compromisers;

int load_compromise(const char *cpf);

#endif