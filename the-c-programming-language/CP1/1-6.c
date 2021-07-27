#include <stdio.h>

void main() {
  int c = getchar();
  printf("Echo the condition %d\n", c != EOF);
  while (c != EOF)
  {
    putchar(c);
    c = getchar();
  }
}
