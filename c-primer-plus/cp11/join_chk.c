#include <stdio.h>
#include <string.h>
#include "common.h"

#define SIZE 30
#define BUGSIZE 13

int main(void) {
  char flower[SIZE];
  char addon[] = "s smell like old shoes";
  char bug[BUGSIZE];
  int available;
  puts("What's your favorite flower?");
  s_gets(flower, SIZE);
  if (strlen(addon) + strlen(flower) + 1 <= SIZE) {
    strcat(flower, addon);
  }
  puts(flower);
  puts("What's your favrite bug?");
  s_gets(bug, BUGSIZE);
  available = BUGSIZE - 1 - strlen(bug);
  strncat(bug, addon, available);
  puts(bug);

  return 0;
}
