#include <stdio.h>

struct complex {
  double real;
  double imaginary;
};

struct complex c1, c2, c3;

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex, struct complex);

int main(void)
{
  double real = 0.1;
  double imaginary = 0.2;
  c1 = make_complex(real, imaginary);
  printf("real is %f and imaginary is %f\n", c1.real, c1.imaginary);

  c2 = (struct complex) {
    .real = 4.5,
    .imaginary = 5.5,
  };

  c3 = (struct complex) {
    .real = 1.0,
    .imaginary = 2.0,
  };

  struct complex c4 = add_complex(c2, c3);
  printf("C4 real is %f and imaginary is %f\n", c4.real, c4.imaginary);
}

struct complex make_complex(double real, double imaginary)
{
  struct complex c4 = {
    .real = real,
    .imaginary = imaginary
  };
  return c4;
}

struct complex add_complex(struct complex co1, struct complex co2)
{
  double real = co1.real + co2.real;
  double imaginary = co1.imaginary + co2.imaginary;

  struct complex c5 = {
    real = real,
    imaginary = imaginary
  };
  return c5;
}
