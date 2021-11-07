#include <utmpx.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SHOWHOST

void show_info(struct utmpx utmp_info);
void show_time(long login_time);

int main(void) {
  struct utmpx* utmp_info;

  setutxent();

  while ((utmp_info = getutxent()) != NULL) {
    show_info(*utmp_info);
  }

  endutxent();

  exit(0);
}

void show_info(struct utmpx utmp_info) {
  if (utmp_info.ut_type != USER_PROCESS) {
    return;
  }
  printf("%-12.12s", utmp_info.ut_user);
  printf(" ");
  printf("%-12.12s", utmp_info.ut_line);
  printf(" ");
  show_time(utmp_info.ut_tv.tv_sec);
#ifdef SHOWHOST
  if (utmp_info.ut_host[0] != '\0') {
    printf("(%12.12s)", utmp_info.ut_host);
  }
#endif
  printf("\n");
}

void show_time(long login_time) {
  char* cp = ctime(&login_time);
  printf("%12.12s", cp + 4);
}

