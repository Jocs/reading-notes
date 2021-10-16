#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t t;
  struct tm *tmp;
  char buf1[16];
  char buf2[64];

  time(&t);
  printf("Time in second: %td\n", t);

  tmp = localtime(&t);
  if (strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0) {
    printf("buffer 1 is not emough\n");
  } else {
    printf("%s\n", buf1);
  }
  if (strftime(buf2, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0) {
    printf("buffer 2 is not emough\n");
  } else {
    printf("%s\n", buf2);
  }

  exit(0);
}