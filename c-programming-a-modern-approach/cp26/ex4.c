#include <stdio.h>
#include <time.h>

int main(void)
{
  int n;
  struct tm *t;
  printf("Enter month:");
  scanf(" %d", &(t->tm_mon));
  printf("Enter day:");
  scanf(" %d", &(t->tm_mday));
  printf("Enter Year:");
  scanf(" %d", &(t->tm_year));
  printf("Enter how many days later:");
  scanf(" %d", &n);
  t->tm_sec = 0;
  t->tm_min = 0;
  t->tm_hour = 0;
  t->tm_isdst = -1;
  t->tm_mday += n;
  t->tm_year -= 1900;
  printf("%.2d-%.2d-%.4d\n", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900);
  mktime(t);

  printf("%.2d-%.2d-%.4d\n", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900);
  return 0;
}