#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ret_val, mypid;
  mypid = getpid();
  printf("my pid is: %d\n", mypid);
  ret_val = fork();
  if (ret_val < 0) {
    perror("fork");
  } else if (ret_val == 0) {
    // parent pid 有可能是 1，因为 parent proces 已经退出，子进程被 init 进程收养。
    printf("In chile my pid is %d, parend pid is: %d\n", getpid(), getppid());
  } else {
    printf("In parent my pid is%d, return val is %d\n", getpid(), ret_val);
  }

  exit(0);
}