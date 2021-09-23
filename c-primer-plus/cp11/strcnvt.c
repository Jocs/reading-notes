#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define SIZE 40

int main(void) {
  char *str = (char *)malloc(SIZE * sizeof(char));
  char *end;
  long value;

  while (s_gets(str, SIZE) && *str != '\0') {
    value = strtol(str, &end, 10);
    printf("base 10, input %s, output %ld, and end at %s (%d)\n", str, value, end, *end);
    value = strtol(str, &end, 16);
    printf("base 16, input %s, output %ld, and end at %s (%d)\n", str, value, end, *end);

    puts("Another number");
  }

  return 0;
}
