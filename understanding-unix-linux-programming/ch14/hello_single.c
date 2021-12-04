#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM 10

void print_msg(char* msg);

int main(void) {
  print_msg("hello ");
  print_msg("world\n");

  exit(0);
}

void print_msg(char* msg) {
  int i;
  for (i = 0; i < NUM; i++) {
    printf("%s", msg);
    fflush(stdout);
    sleep(1);
  }
}