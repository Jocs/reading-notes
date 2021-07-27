#include <stdio.h>
#include <string.h>

int numchar(const char *s, char ch);

int main(void)
{
  char *s = "hello nice to meet you";
  printf("The characher `e` has %d times", numchar(s, 'e'));
}

int numchar(const char *s, char ch)
{
  char *p;
  int count = 0;
  p = strchr(s, ch);
  while (p != NULL) {
    count++;
    p = strchr(p + 1, ch);
  }
  return count;
}