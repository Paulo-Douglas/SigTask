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