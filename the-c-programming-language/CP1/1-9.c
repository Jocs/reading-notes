#include <stdio.h>
#include <stdlib.h>

int main()
{
  int c, i;
  char result[12];
  i = 0;
  while((c = getchar()) != EOF) {
    if (c != ' ' || (c == ' ' && result[i - 1] != ' ')) {
      result[i++] = c;
    }
  }
  result[i] = '\0';

  printf("\n%s\n", result);
}
