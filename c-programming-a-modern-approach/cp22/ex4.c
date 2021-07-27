#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int c_count = 0, w_count = 0, l_count = 0, ch;
  bool in_word = false;
  if (argc != 2) {
    printf("Enter file name\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Can not open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF) {
    c_count++;
    if (isspace(ch)) {
      in_word = false;
    } else if (!in_word) {
      in_word = true;
      w_count++;
    }
    if (ch == '\n')
      l_count++;
  }
  if (ch == EOF) l_count++;
  printf("char count: %d\n", c_count);
  printf("word count: %d\n", w_count);
  printf("line count: %d\n", l_count);
  fclose(fp);
  return 0;
}