#include <stdio.h>

int min(int a, int b);

int main(void) {
  int a, b;
  printf("Please enter two numbers\n");
  while (scanf("%d %d", &a, &b) == 2) {
    while (getchar() != '\n') {
      continue;
    }
    printf("The min number is %d, in %d and %d\n", min(a, b), a, b);
    printf("Please enter another two numbers, enter q to quit.\n");
  }

  printf("Bye");

  return 0;
}

int min(int a, int b) {
  return a > b ? b : a;
}