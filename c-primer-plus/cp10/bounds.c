#include <stdio.h>
#define SIZE 4

int main(void) {
  int value1 = 44;
  int arr[SIZE];
  int value2 = 45;
  int i;
  printf("value1 = %d, value2 = %d\n", value1, value2);
  for (i = -1; i <= SIZE; i++)
    arr[i] = i * 2 + 1;
  for (i = -1; i < 7; i++)
    printf("%2d %d\n", i, arr[i]);
  printf("value1 = %d, value2 = %d\n", value1, value2);
  printf("Address of arr[-1]: %p\n", &arr[-1]);
  printf("Address of arr[4]: %p\n", &arr[4]);
  printf("Address of value1 %p\n", &value1);
  printf("Address of value2: %p\n", &value2);

  return 0;
}