#include "../apue.3e/include/apue.h"
#include <sys/wait.h>
#include <string.h>

char *env_list[] = { "USER=ransixi", "PATH=/tmp", NULL };

int main(void) {
  pid_t pid;
  char *path_val = getenv("PATH");
  printf("PATH: %s\n", path_val);
  // char *new_val = (char *)malloc((strlen(path_val) + 3) * sizeof(char));
  // strcpy(new_val, path_val);
  // strcat(new_val, ":.");
  // printf("NEW PATH: %s\n", new_val);
  // if (setenv("PATH", new_val, 1) == -1) {
  //   err_sys("setenv error");
  // }

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execle("./echo", "echo", "arg 1", "arg 2", (char *)0, env_list) < 0) {
      err_sys("execle error");
    }
  }

  if (waitpid(pid, NULL, 0) < 0) {
    err_sys("wait error");
  }

  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execlp("./echo", "echo", "ARG 1", "ARG 2", (char *)0) < 0) {
      err_sys("execle error");
    }
  }

  exit(0);
}