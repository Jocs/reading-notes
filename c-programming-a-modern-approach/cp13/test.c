#include <stdio.h>

int main(void)
{
  char *str = "hello";
  while (*str) {
    printf("%c\n", *str);
    printf("%d\n", *str - 'a');
    str++;
  }
  return 0;
}