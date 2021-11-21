#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void child_code(int delay);
void parent_code(void);
void sigchld_handler(int signum);

int main(void) {
  int fork_ret;
  fork_ret = fork();

  if (fork_ret == -1) {
    perror("fork");
  } else if (fork_ret == 0) {
    child_code(2);
  } else {
    parent_code();
  }

  exit(0);
}

void child_code(int delay) {
  printf("in child, my pid is %d\nsleep(%d)\n", getpid(), delay);
  sleep(delay);
  printf("out child\n");
}

void parent_code(void) {
  signal(SIGCHLD, sigchld_handler);
  while (1) {
    pause();
  }
}

void sigchld_handler(int signum) {
  printf("in handler and receive SIGCHLD\n");
  exit(0);
}