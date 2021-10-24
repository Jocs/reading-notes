#include <stdlib.h>
#include <unistd.h>
#include "common.h"

int main(void) {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0) {
    puts("fork error");
    exit(1);
  } else if (pid == 0) {
    exit(7);
  }

  if (wait(&status) != pid) {
    puts("wait error");
  }

  pr_exit(status);

  if ((pid = fork()) < 0) {
    puts("fork error");
    exit(1);
  } else if (pid == 0) {
    abort();
  }

  if (wait(&status) != pid) {
    puts("wait error");
  }

  pr_exit(status);

  if ((pid = fork()) < 0) {
    puts("fork error");
    exit(1);
  } else if (pid == 0) {
    status /= 0;
  }

  if (wait(&status) != pid) {
    puts("wait error");
  }

  pr_exit(status);

  exit(0);
}