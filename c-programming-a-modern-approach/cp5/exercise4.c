#include <stdio.h>

int main(void)
{
  int speed;
  printf("请输入风速？\n");
  scanf("%d", &speed);

  if (speed < 1) {
    printf("Calm");
  } else if (speed < 3) {
    printf("Light air");
  } else if (speed < 27) {
    printf("Breeze");
  } else if (speed < 47) {
    printf("Galc");
  } else if (speed < 63) {
    printf("Storm");
  } else {
    printf("Hurricane");
  }
  return 0;
}