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
    child_code(17);
  } else {
    parent_code();
  }

  exit(0);
}

void child_code(int delay) {
  printf("in child, my pid is %d\nsleep(%d)\n", getpid(), delay);
  sleep(delay);
  printf("out child\n");
  exit(17);
}

void parent_code(void) {
  int status;
  int ret_wait = wait(&status);
  int high_8, low_7, bit_7;

  printf("in parent: my pid is %d, wait return %d\n", getpid(), ret_wait);
  high_8 = status >> 8;
  low_7 = status & 0x7F;
  bit_7 = status & 0x80;

  printf("status: exit = %d, sig = %d, core = %d\n", high_8, low_7, bit_7);
}