#include <stdio.h>

int is_prime(int n);

int is_prime(int n)
{
  int i;
  int result = 1;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      result = 0;
      break;
    }
  }
  return result;
}

int main(void)
{
  int digit = 0, n;
  int m;
  printf("Please enter a number:\n");
  scanf("%d", &n);

  do {
    n /= 10;
    digit++;
  } while (n > 0);

  printf("The number you enter has %d digit(s)", digit);

  printf("Please enter a number, and judge weather it is prime\n");
  scanf("%d", &m);
  while(m != 0) {
    if (is_prime(m)) {
      printf("%d is prime\n", m);
    } else {
      printf("%d is not prime\n", m);
    }
    scanf("%d", &m);
  }
}