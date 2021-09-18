#include <stdio.h>

int main(void)
{
  printf("%x %X %#X\n", 31, 31, 31);
  printf("**%d**% d**% d**\n", 6, 6, -6);
  printf("**%5d**%5.3d**%.3d**%05d**\n", 6, 6, 6, 6);

  return 0;
}