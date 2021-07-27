#include <stdio.h>

int main(void)
{
  char s[50];
  printf("enter some words: ");
  gets(s);
  printf("you enter [%s]\n", s);
  return 0;
}