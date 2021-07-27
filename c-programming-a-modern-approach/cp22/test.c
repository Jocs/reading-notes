#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  printf("%#012.5g\n", 29748.6607);
  printf("enter a number:");
  scanf("%d", &n);
  printf("%d %s\n", n, n > 1 ? "widgets" : "widget");
  return 0;
}