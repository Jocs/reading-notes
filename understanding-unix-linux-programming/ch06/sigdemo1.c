#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum);

int main(void) {
  int i;

  signal(SIGINT, signal_handler);
  for (i = 0; i < 5; i++) {
    sleep(1);
    printf("%d\n", i);
  }

  exit(0);
}

void signal_handler(int signum) {
  printf("yaha %d\n", signum);
}