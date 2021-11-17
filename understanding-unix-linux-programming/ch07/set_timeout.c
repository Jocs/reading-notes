#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void set_timeout(void (*)(int), int duration);
void alert(int sgnum);

int main(void) {
  set_timeout(alert, 2);
  exit(0);
}

void set_timeout(void (*fn)(int), int duration) {
  signal(SIGALRM, fn);
  alarm(duration);
  pause();
}

void alert(int sgnum) {
  printf("alert %d\n", sgnum);
}