#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static void exit_1(void);
static void exit_2(void);

int main(void) {
  if (atexit(exit_1) == -1) {
    fprintf(stderr, "atexit error: %s", strerror(errno));
  }
  if (atexit(exit_2) == -1) {
    fprintf(stderr, "atexit error: %s", strerror(errno));
  }
  if (atexit(exit_2) == -1) {
    fprintf(stderr, "atexit error: %s", strerror(errno));
  }
  exit(EXIT_FAILURE);
}

static void exit_1(void) {
  printf("exit from exit_1\n");
}

static void exit_2(void) {
  printf("exit from exit_2\n");
}