#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'
#define SLEN 81

int main(int argc, char *argv[]) {
  FILE *pd;
  long last, count;
  int ch;

  if (argc < 2)
  {
    puts("enter file name.");
    exit(EXIT_FAILURE);
  }

  if ((pd = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can not open %s file", argv[1]);
    exit(EXIT_FAILURE);
  }

  fseek(pd, 0L, SEEK_END);
  last = ftell(pd);

  for (count = 1L; count <= last; count++) {
    fseek(pd, -count, SEEK_END);
    if ((ch = getc(pd)) != CNTL_Z && ch != '\r')
      putc(ch, stdout);
  }

  putchar('\n');
  fclose(pd);
  exit(0);
}