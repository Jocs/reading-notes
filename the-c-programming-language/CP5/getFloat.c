#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);
int getFloat(float *pn);

int getch(void)
{
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE) {
    printf("ungetch: you input too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

int getFloat(float *pn)
{
  char c = getch();
  int sign, base = 10.0;
  while (isspace(c))
    c = getch();
  if (!isdigit(c) && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = c == '-' ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  *pn = 0.0;
  while (isdigit(c)) {
    *pn = *pn * 10.0 + (float) (c - '0');
    c = getch();
  }
  if (c == '.')
    c = getch();
  else {
    ungetch(c);
    return 1;
  }
  while (isdigit(c)) {
    *pn += (float) (c - '0') / base;
    base *= 10.0;
    c = getch();
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return 1;
}

int main(void)
{
  float *t;
  printf("enter a float number:\n");
  if (getFloat(t)) {
    printf("the entered number is %f\n", *t);
  } else {
    printf("can not read you number\n");
  }
  return 0;
}
