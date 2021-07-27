#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int i, seed;
  printf("This program display the first five values of rand.\n");

  for (;;) {
    for (i = 0; i < 5; i++) {
      printf("%d   ", rand());
    }
    printf("\n\n");
    printf("Enter seed:");
    scanf(" %d", &seed);
    if (seed == 0)
      break;
    srand(seed);
  }
  return 0;
}