#include <stdio.h>

int main(void)
{
  int i, n;
  printf("The program prints a table of squares.\n");
  printf("Enter number of entries in table: \n");
  scanf("%d", &n);
  for (i = 0; i <= n; i++) {
    printf("%10d%10d\n", i, i * i);
    if ((i + 1) % 24 == 0) {
      printf("Please enter to continue\n");
      while (getchar() != '\n')
        ;
    }
  }
  return 0;
}