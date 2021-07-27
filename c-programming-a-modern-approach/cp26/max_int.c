#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...);

int main(void)
{
  printf("The max number of 2, 3, 4 is %d\n", max_int(3, 2, 3, 4));
}

int max_int(int n, ...)
{
  va_list ap;
  int i, largest, current;
  va_start(ap, n);
  largest = va_arg(ap, int);
  for (i = 1; i < n; i++) {
    current = va_arg(ap, int);
    if (largest < current)
      largest = current;
  }
  va_end(ap);
  return largest;
}