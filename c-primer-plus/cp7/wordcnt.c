#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(void) {
  char ch;
  char pre;
  int char_count = 0;
  int word_count = 0;
  int line_count = 0;
  int p_line_count = 0;
  bool in_word = false;
  pre = '\n';
  printf("Please enter some text\n");

  while ((ch = getchar()) != STOP) {
    char_count++;
    if (ch == '\n')
      line_count++;
    if (!isspace(ch) && !in_word) {
      in_word = true;
      word_count++;
    }
    if (isspace(ch) && in_word) {
      in_word = false;
    }

    pre = ch;
  }

  if (pre != '\n')
    p_line_count = 1;

  printf(
    "characters: %d, words: %d, lines: %d, partial lines: %d\n",
    char_count, word_count, line_count, p_line_count
  );

  return 0;
}