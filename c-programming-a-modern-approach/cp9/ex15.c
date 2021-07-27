#include <stdio.h>

double middle_number(double, double, double);
long int factter(int num);

int main(void)
{
  double a, b, c;
  int num = 3;
  printf("enter 3 number:\n");
  scanf("%lf%lf%lf", &a, &b, &c);
  printf("the middle number is %f", middle_number(a, b, c));
  printf("fa number is %ld", factter(num));
}

double middle_number(double a, double b, double c)
{
  double result;
  if (a >= b) {
    if (b >= c) result = b;
    else if (a <= c) result = a;
    else result = c;
  } else {
    if (a >= c) result = a;
    else if (b <= c) result = b;
    else result = c;
  }
  return result;
}

long int factter(int num)
{
  long int result = 1;
  while (num > 0) {
    result *= num;
    num--;
  }
  return result;
}