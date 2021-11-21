#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("my pid is: %d\n", getpid());
  fork();
  fork();
  fork();
  printf("after fork: mypid is %d\n", getpid());

  exit(0);
}