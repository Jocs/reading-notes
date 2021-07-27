#include <string.h>
#include <stdio.h>

void reverse(char s[]);
void itoa(int n, char s[]);
int trim(char s[]);

void reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[])
{
  char sign;
  int i = 0;
  sign = n > 0 ? '+' : '-';
  if (n < 0) {
    n = -n;
  }
  do {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if (sign == '-') {
    s[i++] = sign;
  }
  s[i] = '\0';
  reverse(s);
}

int trim(char s[])
{
  int n;
  for (n = strlen(s) - 1; n >= 0; n--) {
    if (s[n] != '\t' && s[n] != '\n' && s[n] != ' ') break;
  }
  s[++n] = '\0';
  return n;
}

int main()
{
  char s[5];
  int n = -12349;
  itoa(n, s);
  printf("%s\n", s);

  char s2[] = "hello ";
  trim(s2);
  printf("%s\n", s2);
  printf("%ld", strlen(s2));
}