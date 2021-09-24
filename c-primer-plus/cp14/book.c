#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TITLE_SIZE 40
#define AUTHOR_SIZE 40

struct book
{
  char title[TITLE_SIZE];
  char author[AUTHOR_SIZE];
  float value;
};

int main(int argc, char *argv[]) {
  struct book library;

  if (argc != 4) {
    fprintf(stderr, "Wrong arguments.");
    exit(EXIT_FAILURE);
  }
  strncpy(library.title, argv[1], TITLE_SIZE - 1);
  strncpy(library.author, argv[2], AUTHOR_SIZE - 1);
  library.value = (float)atoi(argv[3]);

  printf("library: title = %s, author = %s, value = %.2f\n", library.title, library.author, library.value);

  exit(0);
}
