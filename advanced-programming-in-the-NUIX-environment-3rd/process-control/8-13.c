#include "../apue.3e/include/apue.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void print_char(char *);

int main(void) {
  pid_t pid;
  TELL_WAIT();
  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {
    // child process
    print_char("output from child\n");
    TELL_PARENT(getppid());
  }
  else if (pid > 0)
  {
    WAIT_CHILD();
    print_char("output from parent\n");
  }

  exit(0);
}

static void print_char(char * ptr) {
  char *pt = ptr;
  int ch;
  setbuf(stdout, NULL);
  while ((ch = *pt++) != '\0') {
    putchar(ch);
  }
}