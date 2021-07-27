#include <stdio.h>
#include "stack.h"

int main(void)
{
  int i;
  for (i = 0; i < 10; i++){
    push(i);
  }
  while (!is_empty()) {
    i = pop();
    printf("pop number is %d\n", i);
  }
  return 0;
}