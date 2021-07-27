#include <stdio.h>

char *strcat(char *dest, const char *source);

int main(void)
{
  char str[20];
  sprintf(str, "%2d", 20);
  strcat(str, " hello world");
  printf("%s\n", str);
}

char *strcat(char *dest, const char *source)
{
  char *p = dest;
  while (*p)
    p++;
  while ((*p++ = *source++))
    ;
  return dest;
}