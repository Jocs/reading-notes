#include <stdio.h>

void trystat(void);

int main(void) {
  int i;
  for (i = 0; i < 3; i++) {
    trystat();
  }

  return 0;
}

void trystat(void) {
  int try = 1;
  static int stat = 1;
  printf("try: %d, stat: %d\n", try++, stat++);
}