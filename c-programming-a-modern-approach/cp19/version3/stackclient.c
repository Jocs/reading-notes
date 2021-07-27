#include <stdio.h>
#include "stackADT.h"

int main(void)
{
  Stack s1, s2;
  int n;
  s1 = create();
  s2 = create();
  push(s1, 1);
  push(s1, 2);
  n = pop(s1);
  push(s2, n);
  printf("%d\n", pop(s2));
  return 0;
}