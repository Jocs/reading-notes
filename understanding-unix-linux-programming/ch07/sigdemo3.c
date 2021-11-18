#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void terminal_handler(int signum);
void quit_handler(int signum);

#define INPUTLEN 100

int main(void) {
  signal(SIGINT, terminal_handler);
  signal(SIGQUIT, quit_handler);
  char buf[INPUTLEN];
  int nchar;

  do {
    nchar = read(0, buf, INPUTLEN);
    if (nchar == -1) {
      perror("read");
      exit(1);
    }
    buf[nchar] = '\0';
    printf("input: %d, %s\n", nchar, buf);
  } while (strncmp(buf, "quit", 4) != 0);

  exit(0);
}

void terminal_handler(int signum) {
  printf("in terminal\n");
  sleep(2);
  printf("out terminal\n");
}

void quit_handler(int signum) {
  printf("in quit\n");
  sleep(6);
  printf("out quit\n");
}