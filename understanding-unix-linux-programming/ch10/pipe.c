#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// pipe who sort

#define oops(x, n) perror(x);exit(n)

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: pipe cm1 cm2\n");
    exit(1);
  }

  int apipe[2];
  int pid;

  if (pipe(apipe) == -1) {
    oops("pipe", 1);
  }
  pid = fork();
  if (pid < 0) {
    oops("fork", 2);
  } else if (pid == 0) {
    // child process
    close(apipe[0]);
    if (dup2(apipe[1], 1) == -1) {
      oops("dup2 in child, ", 1);
    }
    close(apipe[1]);
    execlp(argv[1], argv[1], NULL);
    oops("child process", 1);
  } else {
    // parent process
    close(apipe[1]);
    if (dup2(apipe[0], 0) == -1) {
      oops("dup2 in parent, ", 1);
    }
    close(apipe[0]);
    execlp(argv[2], argv[2], NULL);
    oops("parent process", 1);
  }

  exit(0);
}