#include <stdio.h>

int main(void)
{
  int i;
  int days;
  int start;
  printf("Enter number of days in month:\n");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat)\n");
  scanf("%d", &start);
  for (i = 0; i < start * 4; i++) {
    printf(" ");
  }
  for (i = 1; i <= days; i++) {
    printf("%4d", i);
    if ((i + start) % 7 == 0) printf("\n");
  }
}