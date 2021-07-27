#include <stdio.h>
#define LEN 10

int main(void)
{
  long int num;
  int digit, i;
  int arr[LEN] = {0};
  printf("Enter a number:\n");
  scanf("%ld", &num);
  while (num > 0) {
    digit = num % 10;
    arr[digit]++;
    num /= 10;
  }
  printf("Digit:       ");
  for (i = 0; i < LEN; i++)
  {
    printf("%4d", i);
  }
  printf("\n");
  printf("Occurences:  ");
  for (i = 0; i < LEN; i++)
  {
    printf("%4d", arr[i]);
  }
  printf("\n");
}