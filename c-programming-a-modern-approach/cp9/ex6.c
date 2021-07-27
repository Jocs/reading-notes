#include <stdio.h>

int digit(long int n, int k);

int main(void)
{
  long int num;
  int k;
  printf("Please enter a number:\n");
  scanf("%ld", &num);
  printf("which number you want\n");
  scanf("%d", &k);
  printf("the number you want is %d", digit(num, k));
  return 0;
}

int digit(long int n, int k)
{
  int number;
  while (k > 0 && n > 0) {
    number = n % 10;
    k--;
    if (k == 0) return number;
    n /= 10;
  }
  return 0;
}