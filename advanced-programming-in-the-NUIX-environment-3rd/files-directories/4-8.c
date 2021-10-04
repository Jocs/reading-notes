#include "../apue.3e/include/apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    err_ret("Usage: a.out <pathname>");
  }
  if (access(argv[1], R_OK) < 0) {
    err_ret("access error for %s", argv[1]);
  } else {
    puts("access ok");
  }
  if (open(argv[1], O_RDONLY) < 0) {
    err_ret("open error for %s", argv[1]);
  } else {
    puts("open ok");
  }

  exit(0);
}