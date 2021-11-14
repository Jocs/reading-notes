#include <stdio.h>
#include <ctype.h>

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == 'z')
      c = 'a';
    if (islower(c))
      c++;
    putchar(c);
  }
}
