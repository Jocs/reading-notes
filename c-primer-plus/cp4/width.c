#include <stdio.h>
#define PAGES 345

int main(void)
{
  printf("*%d*\n", PAGES);
  printf("*%2d*\n", PAGES);
  printf("*%10d*\n", PAGES);
  printf("*%-10d*\n", PAGES);

  return 0;
}