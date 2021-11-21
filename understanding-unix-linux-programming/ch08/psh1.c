#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXARGS 20
#define ARGLEN 100

int execute(char* arglist[]);
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

int execute(char* arglist[]) {
  execvp(arglist[0], arglist);
  perror("execvp failed");
  exit(1);
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
  printf("coped: %s", val);

  return val;
}