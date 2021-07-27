#include <stdio.h>

int strend(char *, char *);

int strend(char *d, char *s)
{
  while (*d != *s)
    d++;
  if (*d == '\0')
    return 0;

  while (*d == *s && *d != '\0') {
    d++;
    s++;
  }
  if (*d == '\0')
    return 1;
  else
    return 0;
}

int main(void)
{
  char *s1 = "hello world";
  char *s2 = "world";

  printf("%s ends with %s: %s\n", s1, s2, strend(s1, s2) ? "Yes" : "No");
}