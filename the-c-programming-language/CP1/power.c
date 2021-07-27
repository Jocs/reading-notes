#include <stdio.h>

#define P 2

int power(int, int);

int main()
{
  int i;
  for (i = 0; i < 10; i++) {
    printf("%d ^ %d \t %d\n", P, i, power(P, i));
  }
}

int power(int base, int n)
{
  int i;
  int result = 1;
  for (i = 1; i <= n; i++) {
    result *= base;
  }
  return result;
}
