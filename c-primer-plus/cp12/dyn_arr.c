#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  double *pt;
  int max;
  int i = 0;
  int number;

  puts("Enter the size of arr.");
  if (scanf("%d", &max) != 1) {
    puts("Wrong input number.");
    exit(EXIT_FAILURE);
  }
  pt = (double *)malloc(max * sizeof(double));
  if (pt == NULL) {
    puts("Can not allocate memary.");
    exit(EXIT_FAILURE);
  }
  puts("Enter the numbers, (q for quit)");
  while (i < max && scanf("%lf", &pt[i]) == 1)
    i++;
  printf("Here are your %d entries:\n", number = i);
  for (i = 0; i < number; i++)
  {
    printf("%7.2lf", pt[i]);
    if (i % 3 == 2)
      putchar('\n');
  }
  putchar('\n');

  free(pt);

  exit(EXIT_SUCCESS);
}