#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;
  if (argc != 2) {
    printf("You need enter filename\n");
    exit(EXIT_FAILURE);
  }
  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("Can not open file\n");
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF) {
    if (ch >= 'a' && ch <= 'z') {
      putc(toupper(ch), stdout);
    } else {
      putchar(ch);
    }
  }
  return 0;
}