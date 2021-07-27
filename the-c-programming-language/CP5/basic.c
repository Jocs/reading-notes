#include <stdio.h>

void swap(int *px, int *py);
int strlength(char *s);
int strlength2(char s[]);
void strcopy(char *s, char *t);
int strcmp1(char *s, char *t);
int strcmp2(char *s, char *t);

void swap(int *px, int *py)
{
  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}

int strlength(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

int strlength2(char *s)
{
  char *p = s;
  while (*p != '\0')
    p++;
  return p - s;
}

void strcopy(char *s, char *t)
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

int strcmp1(char *s, char *t)
{
  int i;
  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') return 0;
  }
  return s[i] - t[i];
}

int strcmp2(char *s, char *t)
{
  while (*s == *t) {
    s++;
    t++;
  }
  return *s > *t;
}

int main()
{
  int x = 1, y[] = {1, 2, 3};
  int z = 5, d = 6;
  int *ip, *px, *py;
  char s[] = "hello world";
  char s2[] = "hello wormd";
  char copy[11];
  px = &z;
  py = &d;
  swap(px, py);
  ip = &y[0];
  printf("%d\n", *(ip + 1));
  printf("%d \t %d\n", z ,d);
  printf("length of y: %d\n", strlength(s));
  printf("length of s by length2: %d\n", strlength2(s));
  strcopy(copy, s);
  printf("%s\n", copy);
  printf("%d\n", strcmp2(s, s2));
}