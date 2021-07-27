#include <stdio.h>

#define N 10

int main(void)
{
  int a[N][N], *p;
  int count = N;

  for (p = &a[0][0]; p <= &a[N - 1][N - 1]; p++)
  {
    if (count == N) {
      *p = 1;
      count = 0;
    } else {
      *p = 0;
      count++;
    }
  }
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%2d", a[i][j]);
    }
    printf("\n");
  }
}