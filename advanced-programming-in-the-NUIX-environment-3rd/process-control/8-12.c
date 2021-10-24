#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void print_char(char *);

int main(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    puts("fork error");
    exit(1);
  } else if (pid == 0) {
    // child process
    print_char("output from child\n");
  } else if (pid > 0) {
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