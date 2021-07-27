#include <string.h>
#include <stdio.h>

void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);

void qsort(char *v[], int left, int right)
{
  int i, last;
  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int main(void)
{
  char *v[] = {
    "hello",
    "nice",
    "wujingwen",
    "jocs",
    "ransixi"
  };
  int i;

  qsort(v, 0, 4);
  for (i = 0; i < 5; i++) {
    printf("%s\n", v[i]);
  }
  return 0;
}