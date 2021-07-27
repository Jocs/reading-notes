#include <stdio.h>

void stringcat(char *dest, char *source);

void stringcat(char *dest, char *source)
{
  while (*dest++)
    ;
  dest--;
  while ((*dest++ = *source++))
    ;
}

int main(void)
{
  char dest[23] = {'h', 'l', '\0'};
  char *source = "hello world";
  stringcat(dest, source);
  printf("%s\n", dest);
}