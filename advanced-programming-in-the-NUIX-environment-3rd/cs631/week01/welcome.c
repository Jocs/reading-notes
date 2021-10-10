#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  printf("Welcome to CS631 Advanced Programming in the UNIX Environment: %s\n", getlogin());

  exit(0);
}