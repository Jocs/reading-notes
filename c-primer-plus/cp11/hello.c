#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int time;
  int i;
  if (argc < 2 ||(time = atoi(argv[1])) < 1) {
    puts("Wrong input");
    exit(EXIT_FAILURE);
  }
  for (i = 0; i < time; i++) {
    puts("Hello world!");
  }
  exit(EXIT_SUCCESS);
}