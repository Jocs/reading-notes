#include <stdio.h>

int main(void)
{
  int nums[3], i, input;
  int result = 0;
  printf("Please enter number: \n");
  scanf("%d", &input);

  for (i = 0; i < 3; i++) {
    nums[i] = input % 10;
    input = input / 10;
  }

  for (i = 0; i < 3; i++) {
    result = result * 10 + nums[i];
  }

  printf("The reverse number is %d\n", result);
}