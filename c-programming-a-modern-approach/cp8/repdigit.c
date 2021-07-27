#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  bool digit_array[10] = { false };
  long int n;
  int digit;
  printf ("Please enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_array[digit]) {
      break;
    }
    digit_array[digit] = true;
    n /= 10;
  }

  if (n > 0) {
    printf("has repeat number\n");
  } else {
    printf("there is no repeat number\n");
  }
}