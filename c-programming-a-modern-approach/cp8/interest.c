#include <stdio.h>

#define NUM_RATES ((int) sizeof(values) / sizeof(values[0]))
#define INITIAL_BALANCE 100.0

int main(void)
{
  double values[5];
  int years, low_rate, i, j;
  printf("Enter years:\n");
  scanf("%d", &years);
  printf("Enter low rate:\n");
  scanf("%d", &low_rate);

  printf("Years:  ");
  for (i = 0; i < NUM_RATES; i++) {
    printf("%8d", low_rate + i);
    values[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (i = 1; i <= years; i++) {
    printf("%-8d", i);
    for (j = 0; j < NUM_RATES; j++) {
      values[j] += (low_rate + j) / 100.0 * values[j];
      printf("%8.2f", values[j]);
    }
    printf("\n");
  }
  return 0;
}