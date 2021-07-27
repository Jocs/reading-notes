#include <math.h>
#include <stdio.h>

void tabulate(double (*f)(double), double start, double end, double incr);

int main(void)
{
  double start, end, increment;
  printf("Enter start number:");
  scanf(" %lf", &start);

  printf("Enter end number:");
  scanf(" %lf", &end);

  printf("Enter increment:");
  scanf(" %lf", &increment);

  printf("\n     x          cos(x)   "
         "\n----------   ---------\n");
  tabulate(cos, start, end, increment);
  printf("\n     x          sin(x)   "
         "\n----------   ---------\n");
  tabulate(sin, start, end, increment);
  printf("\n     x          tan(x)   "
         "\n----------   ---------\n");
  tabulate(tan, start, end, increment);
}

void tabulate(double (*f)(double), double start, double end, double incr)
{
  int num_intervals = ceil((end - start) / incr);
  int i;
  double x;
  for (i = 0; i <= num_intervals; i++) {
    x = start + i * incr;
    printf("%-10.5f%10.5f\n", x, (*f)(x));
  }
}