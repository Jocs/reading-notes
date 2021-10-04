#include "../apue.3e/include/apue.h"
#include <fcntl.h>

int main(int argc, char **argv) {
  int i, fd;
  struct stat statbuf;
  struct timespec times[2];
  for (i = 1; i < argc; i++) {
    if (stat(argv[i], &statbuf) < 0) {
      err_sys("stat error");
      continue;
    }
    if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
      err_sys("open error");
      continue;
    }
    times[0].tv_nsec = statbuf.st_atimensec;
    times[0].tv_sec = statbuf.st_atime;
    times[1].tv_nsec = statbuf.st_mtimensec;
    times[1].tv_sec = statbuf.st_mtime;

    if (futimens(fd, times) < 0)
      err_ret("%s, futimens error", argv[i]);
    close(fd);
  }

  exit(0);
}