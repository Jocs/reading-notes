#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40

int main(int argc, char *argv[]) {
  FILE *in, *out;
  volatile int count = 0;
  char *name = (char *)malloc(SIZE * sizeof(char));
  int ch;

  if (argc < 2) {
    puts("Please enter the filename you want to reduce.");
    exit(EXIT_FAILURE);
  }
  if ((in = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can not open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  strncpy(name, argv[1], SIZE - 5);
  name[SIZE - 5] = '\0';
  strcat(name, ".red");
  if ((out = fopen(name, "w")) == NULL) {
    fprintf(stderr, "Can not open %s\n", name);
    exit(EXIT_FAILURE);
  }
  while((ch = getc(in)) != EOF) {
    if (count++ % 3 == 0) {
      putc(ch, out);
    }
  }
  if (fclose(in) != 0 || fclose(out) != 0) {
    fprintf(stderr, "Close files error\n");
    exit(EXIT_FAILURE);
  }

  exit(0);
}