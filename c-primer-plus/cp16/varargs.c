#include <stdio.h>
#include <stdarg.h>

double sum(int, ...);

int main(void) {
  double s, t;
  s = sum(3, 1.2, 2.3, 4.5);
  t = sum(4, 3.3, 4.5, 6.2, 6.5);

  printf("return value of sum(3, 1.2, 2.3, 4.5) is %.2lf\n", s);
  printf("return value of sum(4, 3.3, 4.5, 6.2, 6.5) is %.2lf\n", t);

  return 0;
}

double sum(int n, ...) {
  int i;
  va_list args;
  double total = 0;
  va_start(args, n);
  for (i = 0; i < n; i++) {
    total += va_arg(args, double);
  }
  va_end(args);

  return total;
}