#include <stdio.h>

typedef struct {
  double real;
  double imaginary;
} Complex;

Complex make_complex(double, double);

int main(void)
{
  Complex c1 = make_complex(1.2, 1.3);
  printf("C1 IS REAL: %f and IMAGINARY: %f\n", c1.real, c1.imaginary);
}

Complex make_complex(double c1, double c2)
{
  return (Complex) {
    .real = c1,
    .imaginary = c2
  };
}
