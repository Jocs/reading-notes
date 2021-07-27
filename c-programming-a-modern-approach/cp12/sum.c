#include <stdio.h>
#define N 10

int sum(int a[]);

int main(void)
{
  int a[N], *p, sum = 0;
  int i;
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  for (p = &a[0]; p < &a[N]; p++)
  {
    sum += *p;
  }
  printf("Sum is %d\n", sum);
}