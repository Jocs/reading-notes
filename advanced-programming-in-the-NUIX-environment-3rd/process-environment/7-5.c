#include <stdlib.h>
#include <stdio.h>

// print all the envs.

int main(void) {
  extern char **environ;
  for (int i = 0; environ[i] != NULL; i++) {
    printf("%s\n", environ[i]);
  }

  exit(0);
}