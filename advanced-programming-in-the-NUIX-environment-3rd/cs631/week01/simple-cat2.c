#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024

int main(void) {
  int c;
  char buf[BUFSIZE];

  while ((c = getchar()) != EOF) {
    if (putchar(c) == EOF) {
      fprintf(stderr, "unable to PUTCHAR %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  }

  if (ferror(stdin)) {
    fprintf(stderr, "read error %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  exit(0);
}