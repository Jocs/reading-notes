#include <stdio.h>

#define MAX 100

int main(void)
{
  char a[MAX];
  char *p;
  printf("Enter a message: ");
  for (p = a; p < a + MAX; p++) {
    scanf("%c", p);
    if (*p == '\n') break;
  }
  for (; p >= a; p--) {
    printf("%c", *p);
  }
}