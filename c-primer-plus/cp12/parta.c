#include <stdio.h>
void report_count(void);
void accumulate(int k);

int count = 0;

int main(void)
{
  int value;
  register int i;
  puts("Input the first number?\n");

  while (scanf("%d", &value) == 1 && value > 0)
  {
    count++;
    for (i = value; i >= 0; i--)
    {
      accumulate(i);
    }
    puts("\nInput another number?\n");
  }
  report_count();
  puts("\nDone");

  return 0;
}

void report_count(void) {
  printf("Loop executed %d times\n", count);
}