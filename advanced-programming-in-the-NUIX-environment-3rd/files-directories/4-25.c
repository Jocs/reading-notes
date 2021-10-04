#include "../apue.3e/include/apue.h"
#include <sys/types.h>

#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

int main(int argc, char **argv) {
  int i;
  struct stat * buf;
  for (i = 1; i < argc; i++) {
    if (stat(argv[i], buf) < 0) {
      err_sys("stat error");
      continue;
    }
    printf("%s (%d/%d)\n", argv[i], major(buf->st_dev), minor(buf->st_dev));
    if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode)) {
      printf("%s (%d/%d)\n", S_ISCHR(buf->st_mode) ? "character" : "block", major(buf->st_dev), minor(buf->st_dev));
    }
  }

  exit(0);
}