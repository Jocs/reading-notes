#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int execute(char** argv) {
  int pid;
  int status = -1;
  if (argv[0] == NULL)
    return 0;
  pid = fork();
  if (pid == -1) {
    perror("fork");
  } else if (pid == 0) {
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    execvp(argv[0], argv);
    perror("execvp error");
    exit(1);
  } else {
    while (wait(&status) != pid)
      ;
  }
  return status;
}
