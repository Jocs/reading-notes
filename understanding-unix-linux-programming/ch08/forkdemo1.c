#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ret_val, mypid;
  mypid = getpid();
  printf("my pid is: %d\n", mypid);
  ret_val = fork();
  sleep(1);
  printf("After fork: my pid is %d, ret val is: %d\n", getpid(), ret_val);

  exit(0);
}