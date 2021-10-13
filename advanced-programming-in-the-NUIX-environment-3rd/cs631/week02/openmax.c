#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void openFiles(int num) {
  struct stat stats;
  int count = 0;
  int fd;

  for (int i = 0; i < num; i++) {
    if (fstat(i, &stats) == 0) {
      printf("Fd #%d is open\n", i);
      count++;
    }
  }

  printf("Currently open files: %d\n", count);

  for (int i = count; i <= num + 1; i++) {
    if ((fd = open("/dev/null", O_RDONLY)) < 0) {
      if (errno == EMFILE) {
        printf("Opened %d additional files, then failed.\n", i - count);
        break;
      } else {
        fprintf(stderr, "Can not open /dev/null %s", strerror(errno));
        break;
      }
    }
  }
}

int main(void) {
  int openmax;
  struct rlimit rlp;

  #ifdef OPEN_MAX
  printf("OPEN_MAX is %d\n", OPEN_MAX);
  #else
  printf("OPEN_MAX is not defined\n");
  #endif

  printf("system(getconf OPEN_MAX)\n");
  fflush(stdout);
  system("getconf OPEN_MAX");

  // sysconf
  errno = 0;
  if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
    if (errno == 0) {
      printf("sysconf is not supported\n");
    } else {
      printf("system error\n");
    }
  }

  printf("sysconf(2) show can open files %d\n", openmax);

  if (getrlimit(RLIMIT_NOFILE, &rlp) != 0) {
    printf("getrlimit error\n");
    exit(EXIT_FAILURE);
  }

  openmax = rlp.rlim_cur;
  printf("getrlimit files %d\n", openmax);

  puts("How many files can be opened by one process??");

  openFiles(openmax);

  exit(0);
}