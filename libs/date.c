#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_mes(char *month) {
  do {
    printf("Month: ");
    scanf(" %s", month);
  } while (atoi(month) < 1 || atoi(month) > 12);
}