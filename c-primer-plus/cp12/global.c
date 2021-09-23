#include <stdio.h>

static int guess = 0;

void guess_num(void);

int main(void) {
  printf("Enter a number and guess.\n");
  scanf("%d", &guess);

  while (guess != 45) {
    guess_num();
  }

  puts("Done");

  return 0;
}

void guess_num(void) {
  printf("Wrong number, again.");
  scanf("%d", &guess);
}