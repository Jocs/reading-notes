#include <ctype.h>
#include <stdio.h>

#include "read_line.h"

int read_line(char *name, int len)
{
  int ch, i = 0;
  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < len) {
      name[i++] = ch;
    }
    ch = getchar();
  }
  name[i] = '\0';
  return i;
}