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

int load_compromise(Compromisers *compromise, const char *team, const char *mod);
int insert_compromise(Compromisers *compromise);
int update_date_compromise(const char delimit, const char *new_data,  const int lenght, int id);

#endif