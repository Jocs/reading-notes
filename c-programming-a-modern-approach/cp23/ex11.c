#include <stdio.h>
#include <string.h>

int main(void)
{
  int i;
  char s[] = "hello nice to meet";
  char *p = s;
  printf("how many char do you want to replace?");
  scanf(" %d", &i);
  int len = strlen(s);
  p = p + len - i;
  memset(p, '!', i);
  printf("%s\n", s);
}