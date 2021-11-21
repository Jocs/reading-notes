#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXARGS 20
#define ARGLEN 100

void execute(char* arglist[]);
char* makestring(char* buf);

int main(void) {
  char* arglist[MAXARGS];
  char buf[ARGLEN];
  int num = 0;

  while (num < MAXARGS) {
    printf("Arg[%d]? ", num);
    if (fgets(buf, ARGLEN, stdin) && *buf != '\n') {
      arglist[num++] = makestring(buf);
    } else if (num > 0) {
      arglist[num] = NULL;
      execute(arglist);
      num = 0;
    }
  }

  return 0;
}

void execute(char* arglist[]) {
  int fork_ret;
  int status;

  fork_ret = fork();
  if (fork_ret == -1) {
    perror("fork");
  } else if (fork_ret == 0) {
    execvp(arglist[0], arglist);
    perror("execvp failed");
    exit(1);
  } else {
    while (wait(&status) != fork_ret)
      ;
    int high_8, low_7, bit_7;

    high_8 = status >> 8;
    low_7 = status & 0x7F;
    bit_7 = status & 0x80;

    printf("status: exit = %d, sig = %d, core = %d\n", high_8, low_7, bit_7);
  }
}

char* makestring(char* buf) {
  buf[strlen(buf) - 1] = '\0';
  char* val;
  val = malloc(strlen(buf) + 1);
  if (val == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }
  strcpy(val, buf);

  return val;
}