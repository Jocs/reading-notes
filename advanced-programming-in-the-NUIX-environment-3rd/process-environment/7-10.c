#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jumbuffer;
static int globval;

int main(void) {
  int autoval;
  register int regival;
  volatile int volaval;
  static int statval;
  globval = 1;
  autoval = 2;
  regival = 3;
  volaval = 4;
  statval = 5;

  if (setjmp(jumbuffer) != 0) {
    printf("after longjum\n");
    printf("global: %d, auto: %d, register: %d, volatile: %d, static: %d\n", globval, autoval, regival, volaval, statval);
    exit(0);
  }

  globval = 91;
  autoval = 92;
  regival = 93;
  volaval = 94;
  statval = 95;

  f1(autoval, regival, volaval, statval);
  exit(0);
}

static void f1(int i, int j, int k, int l) {
  puts("in f1()");
  printf("global: %d, auto: %d, register: %d, volatile: %d, static: %d\n", globval, i, j, k, l);
  f2();
}
static void f2(void) {
  longjmp(jumbuffer, 1);
}