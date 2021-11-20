#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signum);

int main(void) {
  signal(SIGINT, handler);
  pause();
  printf("after pause\n");
}

void handler(int signum) {
  printf("inter\n");
}

