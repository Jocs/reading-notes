#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int globval = 7;
static char buf[] = "hello world\n";

int main(void) {
  int val = 88;
  pid_t pid;
  if ((write(STDOUT_FILENO, buf, strlen(buf))) != strlen(buf)) {
    puts("error in write");
    exit(1);
  }
  printf("before fork\n");
  if ((pid = fork()) < 0) {
    puts("error in fork");
    exit(1);
  } else if (pid == 0) {
    // child process will copy the address space, so it will not change the value in parent process.
    globval++;
    val++;
  } else if (pid > 0) {
    // do nothing.
    sleep(2);
  }
  printf("pid: %d, globval: %d, val: %d\n", getpid(), globval, val);

  exit(0);
}