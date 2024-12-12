#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

#define LINE_COMPROMISE 200

typedef struct
{
    char *id;
    char *name_anything;
    char *situation;
    char *description;
    char *date;
    char *status;

} Compromisers;

int load_compromise(const char *id, Compromisers *compromise);
int insert_compromise(Compromisers *compromise);
int update_date_compromise(const char **id, const char *new_value, const char *field, int length);

#endif