#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isLeap(year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int day_of_year(int year, int month, int day)
{
  int result = day;
  int i, leap;
  leap = isLeap(year);
  for (i = 1; i < month; i++) {
    result += daytab[leap][i];
  }
  return result;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap = isLeap(year);
  int month = 1;
  int day = yearday;
  while (day > daytab[leap][month]) {
    day -= daytab[leap][month];
    month++;
  }
  *pday = day;
  *pmonth = month;
}

int main()
{
  int day = day_of_year(2018, 6, 29);
  printf("today is the %d day of this year!", day);

  int year = 2018;
  int yearday = 180;
  int pmonth = 0, pday = 0;
  month_day(year, yearday, &pmonth, &pday);
  printf("180 is the %d month and %d day", pmonth, pday);
}
