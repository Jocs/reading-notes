#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
  int a = 12;
  int b = 13;
  printf("a = %d and b = %d.\n", a, b);
  swap(&a, &b);
  printf("Now a = %d and b = %d after swap.\n", a, b);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}