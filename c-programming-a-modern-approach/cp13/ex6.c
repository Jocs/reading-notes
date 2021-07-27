#include <stdio.h>

void censor(char s[]);
int f(char *s, char *t)
{
  char *p1, *p2;
  for (p1 = s; *p1; p1++)
  {
    for (p2 = t; *p2; p2++)
    {
      if (*p1 == *p2)
        break;
    }
    if (*p2 == '\0')
      break;
  }
  return p1 - s;
}

int count_space(const char *s)
{
  int i = 0;
  while (*s != '\0') {
    if (*s == ' ')
      i++;
    s++;
  }
  return i;
}

int main(void)
{
  char s[] = "food fool";
  censor(s);
  printf("%s\n", s);
  printf("%d\n", f("abcd", "bcd"));
  printf("Space are %d\n", count_space("abcd edf eee"));
  return 0;
}

void censor(char s[])
{
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'o') {
      s[i] = s[i + 1] = s[i + 2] = 'x';
    }
  }
}

// tired-or-winred?



// f("abcd", "babc") 3
// f("abcd", "bcd") 
// 