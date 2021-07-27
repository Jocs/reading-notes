#include <stdio.h>

void stringncpy(char *, char *, int);
void stringncat(char *, char *, int);
int stringncmp(char *, char *, int);

void stringncpy(char *d, char *s, int n)
{
  int i = 0;
  while (i++ < n && (*d++ = *s++))
    ;
}

void stringncat(char *d, char *s, int n)
{
  int i = 0;
  while (*d != '\0')
    d++;
  while (i++ < n && (*d++ = *s++))
    ;
}

int stringncmp(char *d, char *s, int n)
{
  int i = 0;
  while (++i < n && *d == *s && *d != '\0') {
    d++;
    s++;
  }
  if (i == n - 1)
    return 0;
  return *d - *s;
}

int main(void)
{
  char s1[20] = {'h', 'e', ' ', '\0'};
  char *s2 = "jocs";

  stringncat(s1, s2, 3);
  printf("%s\n", s1);

  char *s3 = "hello";
  char *s4 = "helle";
  printf("%d\n", stringncmp(s3, s4, 5));
  return 0;
}