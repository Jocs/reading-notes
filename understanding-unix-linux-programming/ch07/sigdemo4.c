#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define INPUTLEN 100

void inthandler(int signum);

int main(void) {
  struct sigaction new_action;
  sigset_t block;
  char buf[INPUTLEN];

  new_action.__sigaction_u.__sa_handler = inthandler;
  new_action.sa_flags = SA_RESETHAND; // 捕鼠器模式，只捕获一次, once
  sigemptyset(&block);
  sigaddset(&block, SIGQUIT); // 直接阻塞 SIGQUIT, 当 inthandler 处理完在处理 QUIT 信号
  new_action.sa_mask = block;

  if (sigaction(SIGINT, &new_action, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }

  while (1) {
    fgets(buf, INPUTLEN, stdin);
    printf("%s\n", buf);
  }
}

void inthandler(int signum) {
  printf("in int handler\n");
  sleep(5);
  printf("out int handler\n");
}