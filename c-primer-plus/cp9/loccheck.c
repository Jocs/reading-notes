#include <stdio.h>

void mikado(int);

int main(void) {
  int a = 11;
  int b = 12;
  printf("In mikado a = %d, and &a = %p\n", a, &a);
  printf("In mikado b = %d, and &b = %p\n", b, &b);
  mikado(a);

  return 0;
}

void mikado(int a) {
  int b = 12;
  printf("In mikado a = %d, and &a = %p\n", a, &a);
  printf("In mikado b = %d, and &b = %p\n", b, &b);
}