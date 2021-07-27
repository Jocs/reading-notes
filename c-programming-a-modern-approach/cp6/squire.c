#include <stdio.h>

int main(void)
{
  int i = 0, n;
  printf("Enter a number:\n");
  scanf("%d", &n);
  for (; i * i <= n; i += 2) {
    printf("%d\n", i * i);
  }
}