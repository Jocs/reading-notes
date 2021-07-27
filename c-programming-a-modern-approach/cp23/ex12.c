#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  int ch;
  bool not_end = false;
  while ((ch = getchar()) != EOF) {
    if (not_end) {
      putchar(ch);
    } else if (!isspace(ch)) {
      not_end = true;
      putchar(ch);
    } 
    if (ch == '\n') {
      not_end = false;
    }
  }
  return 0;
}