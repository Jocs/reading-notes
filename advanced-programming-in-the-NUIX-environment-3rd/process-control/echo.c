#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  int i;
  char **ptr;
  extern char **environ;

  printf("argv:\n");
  for (i = 0; i < argc; i++) {
    printf("arg[%d]: %s\n", i, argv[i]);
  }

  printf("environments:\n");
  ptr = environ;
  while (*ptr != NULL) {
    printf("%s\n", *ptr);
    ptr++;
  }

  exit(0);
}