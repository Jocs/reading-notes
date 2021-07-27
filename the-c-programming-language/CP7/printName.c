#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  printf("%s\n", argv[1]);
  char *name = argv[1];
  while (*name != '\0') {
    if (*name >= 'a' && *name <= 'z') {
      printf("%c", toupper(*name));
    } else {
      printf("%c", tolower(*name));
    }
    name++;
  }
  printf("\n");
  return 0;
}
