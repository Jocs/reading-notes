#include <stdio.h>

int main(void)
{
  int hour, minute;
  printf("Enter a 24-hour time:\n");
  scanf("%d:%d", &hour, &minute);
  printf("Equivalent 12-hour is %d:%.2d\n", hour == 0 ? 12 : (hour > 12 ? hour - 12 : hour), minute);
  return 0;
}