#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"

enum spectrum
{
  red,
  orange,
  yellow,
  green,
  blue,
  violet
};

const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

#define LEN 30

int main(void) {
  char choice[LEN];
  enum spectrum color;
  bool color_is_found = false;

  while (s_get(choice, LEN) != NULL && choice[0] != '\0') {
    for (color = red; color <= violet; color++) {
      if (strcmp(colors[color], choice) == 0) {
        color_is_found = true;
        break;
      }
    }

    if (color_is_found) {
      printf("You found the color: %s\n", colors[color]);
      break;
    }
    else
    {
      puts("Color is not found.");
      puts("Enter the next color.");
    }
  }

  return 0;
}