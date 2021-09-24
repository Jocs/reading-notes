#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 41

int main(void) {
  FILE *fd;
  char word[SIZE];
  puts("Input some words, press '#' to quit.");
  if ((fd = fopen("wordy", "a+")) == NULL) {
    fprintf(stderr, "Can not open wordy\n");
    exit(EXIT_FAILURE);
  }
  while (fscanf(stdin, "%s", word) == 1 && word[0] != '#') {
    fprintf(fd, "%s ", word);
  }
  rewind(fd);
  puts("\nWords:\n");
  while (fscanf(fd, "%s", word) == 1) {
    puts(word);
  }

  if (fclose(fd) != 0) {
    fprintf(stderr, "Close file error\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}