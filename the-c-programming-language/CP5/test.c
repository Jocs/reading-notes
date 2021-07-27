#include <stdio.h>

int main(void)
{
  int a[] = {1, 2, 3};
  if (a + 1 == &a[1]) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  int *pn = a;
  printf("%d\n", *pn++);
  return 0;
}
