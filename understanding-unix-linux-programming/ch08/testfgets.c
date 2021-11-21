#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buf[20];
  while (1) {
    printf("input buf\n");
    if (fgets(buf, 20, stdin) && buf[0] != '\n') {
      printf("%s\n", buf);
    } else {
      exit(0);
    }
  }
  exit(0);
}