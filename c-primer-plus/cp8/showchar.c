#include <stdio.h>

void display(char ch, int width, int height);

int main(void) {
  int row, column;
  char ch;
  printf("Please enter a character and two integers\n");
  while ((ch = getchar()) != '\n') {
    if (scanf("%d %d", &row, &column) != 2) {
      printf("You need input two intergers\n");
      break;
    }
    display(ch, row, column);
    while ((ch = getchar()) != '\n')
      continue;
    printf("Please enter another character and two integers\n");
    printf("Enter a newline to quit.\n");
  }

  printf("Bye!\n");

  return 0;
}

void display(char ch, int width, int height) {
  int i, j;
  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      putchar(ch);
    }

    printf("\n");
  }
}