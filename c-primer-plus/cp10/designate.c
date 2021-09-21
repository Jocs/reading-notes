#include <stdio.h>
#define MONTHS 12

int main(void) {
  int days[MONTHS] = {
    31, 28, 31, [3] = 30, 31, 30, [1] = 29
  };
  int i;

  for (i = 0; i < MONTHS; i++) {
    printf("Month %d has %d days\n", i + 1, days[i]);
  }

  return 0;
}