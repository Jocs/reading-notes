#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t current = time(NULL);
  struct tm *p = localtime(&current);
  int hour;
  char time_str[21];

  char am_or_pm;

  printf("The default time string\n");
  puts(ctime(&current));

  printf("Time string by strftime\n");
  strftime(time_str, sizeof(time_str), "%m-%d-%Y   %I:%M %p", p);
  puts(time_str);

  printf("Time string by struct tm\n");
  hour = p->tm_hour;
  if (hour < 12) {
    am_or_pm = 'a';
  } else {
    hour -= 12;
    am_or_pm = 'p';
  }

  if (hour == 0) {
    hour = 12;
  }

  printf("%.2d-%.2d-%.4d   %d:%.2d %c\n", p->tm_mon + 1, p->tm_mday, p->tm_year + 1900, hour, p->tm_min, am_or_pm);

  return 0;
}