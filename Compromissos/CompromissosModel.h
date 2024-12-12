#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

#define LINE_COMPROMISE 200

typedef struct
{
    char id[4];
    char title[100];
    char description[100];
    char date[11];
    char type;
    char priority;
    char status;

} Compromisers;

int insert_compromise(Compromisers *compromise);
Compromisers * load_compromise(const char *id);
int update_date_compromise(const char **id, const char *new_value, const char *field, int length);

#endif