#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024

int main(void) {
  int n;
  char buf[BUFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      fprintf(stderr, "unable to write %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  }

  if (n < 0) {
    fprintf(stderr, "read error %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  exit(0);
}