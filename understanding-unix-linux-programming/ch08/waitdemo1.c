#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void child_code(int delay);
void parent_code(void);

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
  printf("in parent: my pid is %d, wait return %d\n", getpid(), wait(NULL));
}