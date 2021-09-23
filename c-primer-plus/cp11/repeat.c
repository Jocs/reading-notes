#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  if (argc < 2) {
    puts("You need at least input one arguments.");
    exit(EXIT_FAILURE);
  }
  printf("This program has %d arguments:\n", argc - 1);
  for (i = 1; i < argc; i++) {
    printf("%d) %s\n", i, argv[i]);
  }

  exit(EXIT_SUCCESS);
}