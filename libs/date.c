#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void ler_mes(char *month) {
  do {
    printf("Month: ");
    scanf(" %s", month);
  } while (atoi(month) < 1 || atoi(month) > 12);
}

void ler_dia(char *day, int max_day) {
  do {
    printf("Day: ");
    scanf(" %s", day);
  } while (atoi(day) < 1 || atoi(day) > max_day);
}

int ano_bissexto(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return 1;
  }
  return 0;
}

void ler_data(char *day, char *month) {
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = year_now();

  ler_mes(month);
  int month_int = atoi(month);

  if (month_int == 2 && ano_bissexto(year)) {
    days_in_month[2] = 29;
  }

  ler_dia(day, days_in_month[month_int]);
}