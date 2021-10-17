#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  for (int i = 0; argv[i] != NULL; i++) {
    printf("%s\n", argv[i]);
  }
  exit(0);
}