#include <stdio.h>
#include "common.h"
#include <string.h>

#define SIZE 80

int main(void) {
  char flower[SIZE];
  char addon[] = "s smell like old shoes.";
  puts("What's your favorite flower?");
  if (s_gets(flower, SIZE)) {
    strcat(flower, addon);
    puts(flower);
    puts(addon);
  } else {
    puts("End of file encountered.");
  }

  puts("Bye.");

  return 0;
}