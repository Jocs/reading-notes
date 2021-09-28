#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void show_array(const int ar[], int n);
_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");

int main(void) {
  int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target[SIZE];
  double curiout[SIZE / 2] = {2.0, 3.0, 4.0, 5.0, 6.0};
  memcpy(target, values, 10 * sizeof(int));
  show_array(target, SIZE);
  memmove(values + 2, values, 5 * sizeof(int));
  show_array(values, SIZE);

  memcpy(target, curiout, 5 * sizeof(double));

  show_array(target, SIZE / 2);
  show_array(target + 5, SIZE / 2);

  return 0;
}

void show_array(const int ar[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}