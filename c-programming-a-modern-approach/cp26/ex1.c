#include <stdio.h>
#include <stdlib.h>

int rand_range(int n);

int main(void)
{
  int i, num;
  for (i = 0; i < 1000; i++) {
    num = rand();
    // printf(num % 2 == 0 ? "0 " : "1 ");
  }

  for (i = 0; i < 10; i++) {
    printf("%d ", rand_range(10));
  }
  return 0;
}

int rand_range(int n)
{
  return (int) (float) rand() / (float) RAND_MAX * (float) n;
}