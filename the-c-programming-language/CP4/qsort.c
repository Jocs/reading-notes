#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);

void swap(int v[], int i, int j)
{
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right) {
    return;
  }

  swap (v, left, (left + right) / 2);

  last = left;

  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

int main()
{
  int i;
  int v[] = { 3, 6, 8, 1, 2, 6, 7, 3, 0, 12, 4, 53 };
  qsort(v, 0, 11);
  for (i = 0; i < 12; i++) {
    printf("%d\n", v[i]);
  }
}
