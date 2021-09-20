#include <stdio.h>

void to_binary(unsigned long num);

int main(void) {
  unsigned long number;
  printf("Enter an integer (q to quit):\n");

  while (scanf("%lu", &number) == 1) {
    printf("Binary equivalent: ");
    to_binary(number);
    putchar('\n');

    printf("Enter an integer (q to quit):\n");
  }

  printf("Bye!\n");

  return 0;
}

void to_binary(unsigned long num) {
  int n = num % 2;
  if (num / 2 > 0)
    to_binary(num / 2);
  putchar(n == 0 ? '0' : '1');
}