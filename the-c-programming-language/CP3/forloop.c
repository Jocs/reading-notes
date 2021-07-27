#include <stdio.h>

int isSpace(char c);
int isDigit(char c);
int atoi(char s[]);

int main()
{
  char s[5] = "12345";
  int n = atoi(s);
  printf("%d", n);
}

int isSpace(char c)
{
  if (c == '\n' || c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

int isDigit(char c)
{
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}

int atoi(char s[])
{
  int i;
  int sign;
  int n;
  for (i = 0; isSpace(s[i]); i++)
    ;
  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (n = 0; isDigit(s[i]); i++)
    n = n * 10 + (s[i] - '0');
  return sign * n;
}