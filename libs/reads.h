#ifndef READS_H
#define READS_H

void read_string(char *title);
void read_phone(char *phone);
void read_cpf(char *cpf);
void read_description(char *description);
void read_date_with_year(char *day, char *month, char *year);
void read_date_without_year(char *day, char *month);
void read_time(char *time);
void read_generic_123(char *input);
void read_month(char *month);
void read_day(char *day, char *month);

#endif // READS_H