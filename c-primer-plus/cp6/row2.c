#include <stdio.h>

int main(void){
  const int ROW = 6;
  const int COLUMN = 6;

  for (int i = 0; i < ROW; i++) {
    for (char c = ('A' + i); c < ('A' + COLUMN); c++)
      printf(" %c ", c);
    printf("\n");
  }

  return 0;
}