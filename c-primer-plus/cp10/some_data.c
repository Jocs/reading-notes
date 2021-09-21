#include <stdio.h>
#define SIZE 4

int main(void) {
  int data[SIZE] = {1, 2};
  int i;
  for (i = 0; i < SIZE; i++)
    printf("%d ", data[i]);
  printf("\n");

  return 0;
}