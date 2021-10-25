#include "../apue.3e/include/apue.h"
#include "common.h"
#include <sys/times.h>
#include <stdlib.h>
#include <stdio.h>

static void do_cmd(char *);
static void pr_times(clock_t, struct tms, struct tms);

int main(int argc, char **argv) {
  int i;

  for (i = 1; i < argc; i++) {
    do_cmd(argv[i]);
  }

  exit(0);
}

static void do_cmd(char * cmd) {
  struct tms time_start, time_end;
  clock_t start, end;
  int status;
  putchar('\n');
  printf("Command: %s\n", cmd);
  start = times(&time_start);
  if ((status = system(cmd)) < 0) {
    err_sys("system error");
  }
  end = times(&time_end);

  pr_times(end - start, time_start, time_end);
  pr_exit(status);
}

static void pr_times(clock_t real, struct tms start, struct tms end) {
  static long clk = 0;
  if (clk == 0) {
    clk = sysconf(_SC_CLK_TCK);
  }

  printf("Clock time %7.2f\n", (double) (real / clk));
  printf("User time %7.2f\n", (double)((end.tms_utime - start.tms_utime) / clk));
  printf("System time %7.2f\n", (double)((end.tms_stime - start.tms_stime) / clk));
  printf("Child process User time %7.2f\n", (double)((end.tms_cutime - start.tms_cutime) / clk));
  printf("Child process system time %7.2f\n", (double)((end.tms_cstime - start.tms_cstime) / clk));
}