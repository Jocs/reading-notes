#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *);

char *duplicate(char str[])
{
  char *s = malloc(strlen(str) + 1);
  if (s == NULL)
    return NULL;
  strcpy(s, str);
  return s;
}

int main(void)
{
  char str[5] = "hell";
  printf("%s\n", duplicate(str));
}
