#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", X)

int main(void) {
  int x = 5;
  int z;

  printf("x = %d\n", x); // x = 5
  z = SQUARE(x);
  printf("Evaluating SQUARE(x):");
  PR(z); // The result is 25
  z = SQUARE(2);
  printf("Evaluating SQUARE(2):");
  PR(z); // The result is 4
  printf("Evaluating SQUARE(X+2)");
  PR(SQUARE(x + 2)); // The result is 17
  printf("Evaluating 100/SQUARE(2):");
  PR(100 / SQUARE(2)); //The result is 100
  printf("x is %d.\n", x);
  printf("Evaluating SQUARE(++x):");
  PR(SQUARE(++x)); // The result is 42
  printf("After incrementing, x is %d.\n", x);

  return 0;
}