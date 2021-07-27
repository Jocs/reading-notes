#include <stdio.h>

struct {
  double real;
  double imaginary;
} c1 = { 0.0, 0.1 }, c2 = {.real = 1.0, .imaginary = 0.0 }, c3;

int main(void)
{
  c3.real = c1.real + c2.real;
  c3.imaginary = c1.imaginary + c2.imaginary;
  printf("read %f\n", c3.real);
  printf("imaginary: %f\n", c3.imaginary);
}
