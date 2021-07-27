#include <stdio.h>
#include "word.h"

int read_char(void)
{
  int ch;
  ch = getchar();
  if (ch == '\n' || ch == '\t')
    ch = ' ';

  return ch;
}

void read_word(char *word, int len)
{
  int pos = 0, ch;
  while ((ch = read_char()) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len) {
      word[pos++] = ch;
    }
    ch = read_char();
  }
  word[pos] = '\0';
}