#include <stdio.h>

void reverse(char s[]) {
  int l = 0;
  while (s[l++] != '\0')
    ;
  l--;
  printf("%d", l);
  int i;
  int j;
  int temp;
  for (i = 0, j = l - 1; i < j; ++i, --j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  unsigned num;

  if ((sign = n) < 0) /* record sign */
    num = (unsigned) -n;           /* make n positive */
  i = 0;

  do
  { /* generate digits in reverse order */
    s[i++] = num % 10 + '0'; /* get next digit */
  } while ((num /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
  int num = -2147483648;
  char s[20];
  itoa(num, s);

  printf("the result is: %s\n", s);
}