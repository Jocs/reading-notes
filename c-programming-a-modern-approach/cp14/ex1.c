#include <stdio.h>

#define PRINT_INT(n) printf(#n " = %d\n", n)

int main(void)
{
  int i = 3, j = 5;
  PRINT_INT(i / j);
  return 0;
}