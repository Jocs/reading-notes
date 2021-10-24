#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    puts("fork error");
    exit(1);
  } else if (pid == 0) {
    if((pid = fork()) < 0) {
      puts("fork error in child process");
      exit(1);
    } else if (pid > 0) {
      exit(0);
    }

    sleep(2);
    printf("second child pid: %d, parent id: %d\n", getpid(), getppid());
    exit(0);
  }
  if (waitpid(pid, NULL, 0) != pid) {
    puts("wait error");
    exit(1);
  }

  exit(0);
}