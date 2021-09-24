#include <stdio.h>

static int total = 0;
void accumulate(int k);
void accumulate(int k)
{
  static int sub_total = 0;
  if (k == 0)
  {
    printf("Total = %d, subTotal = %d\n", total, sub_total);
    sub_total = 0;
  }
  else
  {
    total += k;
    sub_total += k;
  }
}