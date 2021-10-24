#include "../apue.3e/include/apue.h"
#include "common.h"
#include <errno.h>
#include <unistd.h>

int my_system(const char *cmdstring) {
  pid_t pid;
  int status;

  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {
    execlp("sh", "sh", "-c", cmdstring, (char *)0);
    _exit(127);
  }
  else if (pid > 0)
  {
    while (waitpid(pid, &status, 0) < 0) {
      if (errno != EINTR) {
        status = -1;
        break;
      }
    }
  }

  return status;
}

int main(int argc, char **argv) {
  int status = my_system(argv[1]);
  pr_exit(status);

  exit(0);
}