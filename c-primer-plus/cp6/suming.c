#include <stdio.h>

int main(void)
{
  long sum = 0L;
  int status;
  long num;
  printf("Please enter a number(q for quit)\n");
  status = scanf("%ld", &num);
  while (status == 1)
  {
    sum += num;
    printf("Please enter another number(q for quit)\n");
    status = scanf("%ld", &num);
  }
  printf("The sum is: %ld\n", sum);

  return 0;
}