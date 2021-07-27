#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *source, *dest;
  int ch;

  if (argc != 3) {
    fprintf(stderr, "There need no two arg\n");
    exit(EXIT_FAILURE);
  }

  if ((source = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can not open source file\n");
    exit(EXIT_FAILURE);
  }

  if ((dest = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can not open dest file\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(source)) != EOF) {
    if (putc(ch, dest) == EOF) {
      printf("Error happened!\n");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}