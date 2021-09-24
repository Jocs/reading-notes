#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char flower[20] = "rose";
  flower[10] = '\0';
  strcat(flower, " world");
  puts(flower);

  exit(0);
}