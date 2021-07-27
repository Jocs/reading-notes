#include <stdio.h>

int main(void)
{
  int m, n, temp;
  printf("Enter two integers:\n");
  scanf("%d %d", &m, &n);

  do {
    temp = m % n;
    m = n;
    n = temp;
  } while (n != 0);

  printf("GCD is %d", m);
}