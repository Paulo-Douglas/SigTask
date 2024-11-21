#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void read_month(char *month) {
  do {
    printf("| Mês: ");
    scanf(" %s", month);
    if(atoi(month) < 1 || atoi(month) > 12) {
      printf("| Mês inválido!\n");
      printf("| Tente novamente: ");
    }
  } while (atoi(month) < 1 || atoi(month) > 12);
}

void read_day(char *day, int max_day) {
  do {
    printf("| Dia: ");
    scanf(" %s", day);
    if(atoi(day) < 1 || atoi(day) > max_day) {
      printf("| Dia inválido!\n");
      printf("| Tente novamente: ");
    }
  } while (atoi(day) < 1 || atoi(day) > max_day);
}

int year_bissexto(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return 1;
  }
  return 0;
}

void read_date(char *day, char *month) {
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = year_now();

  read_month(month);
  int month_int = atoi(month);

  if (month_int == 2 && year_bissexto(year)) {
    days_in_month[2] = 29;
  }

  read_day(day, days_in_month[month_int]);
}