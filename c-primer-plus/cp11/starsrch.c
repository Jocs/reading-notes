#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LISTSIZE 6

int main(void) {
  const char *list[LISTSIZE] = {
    "astronomy", "astounding", "astrophysics", "ostracize", "asterism", "astrophobia"
  };
  volatile short count = 0;
  int i;
  for (i = 0; i < LISTSIZE; i++) {
    if (strncmp(list[i], "astro", 5) == 0) {
      printf("Found %s\n", list[i]);
      count++;
    }
  }

  printf("We found %d words start width 'astro'\n", count);

  exit(0);
}