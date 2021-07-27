#include <stdio.h>

void shellSort(int v[], int n);

void shellSort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}

int main() {
  int v[] = {3, 4, 6, 1, 3, 5};
  int i;

  shellSort(v, 4);
  for (i = 0; i < 6; i++) {
    printf("%d", v[i]);
  }
}