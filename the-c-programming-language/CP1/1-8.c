#include<stdio.h>

int main()
{
  int c, nl, tl, sl;
  nl = 0;
  tl = 0;
  sl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nl++;
    } else if (c == '\t') {
      tl++;
    } else if (c == ' ') {
      sl++;
    }
  }

  printf("The \\n number is: %d\n", nl);
  printf("The \\t number is: %d\n", tl);
  printf("The \\s number is: %d\n", sl);
}
