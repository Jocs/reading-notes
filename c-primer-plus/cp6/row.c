#include <stdio.h>
#define ROW 6
#define COLUMN 10

int main(void)
{
  for (int i = 0; i < ROW; i++)
  {
    for (char c = 'A'; c < ('A' + COLUMN); c++)
      printf(" %c ", c);
    printf("\n");
  }

  return 0;
}