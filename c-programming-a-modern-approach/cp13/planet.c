#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int equal(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
  char *planets[] = {
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptune",
    "Pluto"
  };

  int i, j;
  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      if (equal(argv[i], planets[j])) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }
    if (j == NUM_PLANETS)
    {
      printf("%s is not a planet\n", argv[i]);
    }
  }
}

int equal(const char *str1, const char *str2)
{
  while (toupper(*str1) == toupper(*str2) && *str2 != '\0' && *str1 != '\0') {
    str1++;
    str2++;
  }
  if (*str1 == '\0' && *str2 == '\0') return 1;
  else return 0;
}