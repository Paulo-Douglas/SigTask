#ifndef COMPROMISSOSMODEL_H
#define COMPROMISSOSMODEL_H

#define LINE_COMPROMISE 200

typedef struct
{
    int team_id;
    char *title;
    char *description;
    char *start_date;
    char *end_date;
    char *time;
    char *priority;
    char *status;

} Compromisers;

int load_compromise(Compromisers *compromise, const char *id);
int insert_compromise(Compromisers *compromise);
int update_date_compromise(const char **id, const char *new_value, const char *field, int length);

#endif