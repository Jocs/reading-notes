#include <stdio.h>
#include <math.h>

float round_nearest(float n, int i);

int main(void)
{
  float n;
  int i;
  printf("Please enter a number:");
  scanf(" %f", &n);
  printf("Please enter decimal:");
  scanf(" %d", &i);

  printf("The result is %.*f\n", i, round_nearest(n, i));
}

float round_nearest(float n, int i)
{
  float temp = n * powf(10.0, (float) i);
  temp = temp <= 0.0 ? ceil(temp - 0.5) : round(temp + 0.5);
  return temp / powf(10.0, (float) i);
}