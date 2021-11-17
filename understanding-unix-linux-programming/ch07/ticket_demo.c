#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void countdown(int signum);
int ticket(int);

int main(void) {
  signal(SIGALRM, countdown);
  if (ticket(500) == -1) {
    strerror(errno);
    exit(1);
  } else {
    while (1) {
      printf("in while\n");
      pause();
    }
  }

  exit(0);
}

void countdown(int signum) {
  static int num = 10;
  printf("Countdown: %d\n", num--);
  fflush(stdout);

  if (num < 0) {
    printf("done\n");
    exit(0);
  }
}

int ticket(int num) {
  struct itimerval new_timeset;
  long n_secs;
  int n_nsecs;

  n_secs = (long)num / 1000;
  n_nsecs = (num % 1000) * 1000;

  new_timeset.it_value.tv_sec = n_secs;
  new_timeset.it_value.tv_usec = n_nsecs;
  new_timeset.it_interval.tv_sec = n_secs;
  new_timeset.it_interval.tv_usec = n_nsecs;

  return setitimer(ITIMER_REAL, &new_timeset, NULL);
}