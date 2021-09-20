#include <stdio.h>
#include <string.h> // need use strlen();

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 mEGABUCK Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void show_n_char(char ch, int num);

int main(void) {
  int spaces;
  show_n_char('*', WIDTH);
  printf("\n");
  show_n_char(SPACE, 12);
  printf("%s\n", NAME);
  spaces = (40 - strlen(ADDRESS)) / 2;
  show_n_char(SPACE, spaces);
  printf("%s\n", ADDRESS);
  show_n_char(SPACE, (40 - strlen(PLACE)) / 2);
  printf("%s\n", PLACE);
  show_n_char('*', WIDTH);
  printf("\n");

  return 0;
}

void show_n_char(char ch, int num) {
  int count;
  for (count = 1; count <= num; count++) {
    putchar(ch);
  }
}