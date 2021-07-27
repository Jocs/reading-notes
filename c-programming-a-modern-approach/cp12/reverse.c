#include <stdio.h>

#define N 10


int main(void)
{
  int a[10], *p;
  printf("Enter 10 numbers:");
  for (p = a; p < a + N; p++) {
    scanf("%d", p);
  }

  for (p = a + N - 1; p >= a; p--) {
    printf("%4d", *p);
  }
}
