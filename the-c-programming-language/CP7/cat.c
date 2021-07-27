#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[])
{
  FILE *fp;
  int i;
  if (argc == 1) {
    filecopy(stdin, stdout);
  } else {
    for (i = 1; i < argc; i++) {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
        printf("Can not open %s\n", argv[i]);
        return 1;
      } else {
        filecopy(fp, stdout);
      }
    }
  }
  return 0;
}

void filecopy(FILE *from, FILE *to)
{
  int c;
  while ((c = getc(from)) != EOF) {
    putc(c, to);
  }
}