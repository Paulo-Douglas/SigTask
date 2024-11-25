#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

typedef struct
{
    char *team_id;
    char *title;
    char *description;
    char *start_date;
    char *end_date;
    char *time;
    char *priority;

} Compromisers;

int load_compromise(const char *cpf);

#endif