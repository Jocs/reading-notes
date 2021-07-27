#include <stdio.h>

int main()
{
  int c, i;
  char r[100];
  i = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      r[i++] = '\\';
      r[i++] = 'n';
    } else if (c == '\t') {
      r[i++] = '\\';
      r[i++] = 't';
    } else if (c == '\\') {
      r[i++] = '\\';
      r[i++] = '\\';
    } else {
      r[i++] = c;
    }
  }

  printf("\n%s\n", r);
}
