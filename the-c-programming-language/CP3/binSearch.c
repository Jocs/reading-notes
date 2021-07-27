#include <stdio.h>

int binSearch(int x, int v[], int n);

int main() {
  int v[100];
  int i;
  for (i = 0; i < 100; i++) {
    v[i] = i + 1;
  }
  printf("%d", binSearch(50, v, 100));
}

int binSearch(int x, int v[], int n)
{
  int low, high, middle;
  low = 0;
  high = n - 1;
  while (low <= high) {
    middle = (low + high) / 2;
    if (x < v[middle]) {
      high = middle - 1;
    } else if (x > v[middle]) {
      low = middle + 1;
    } else {
      return middle;
    }
  }
  return -1;
}