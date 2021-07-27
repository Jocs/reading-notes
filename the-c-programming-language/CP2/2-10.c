#include<stdio.h>

char lower(char a)
{
  return a < 'a' ? 'a' + (a - 'A') : a;
}

int main()
{
  printf("The A lowercase is %c\n", lower('A'));
}