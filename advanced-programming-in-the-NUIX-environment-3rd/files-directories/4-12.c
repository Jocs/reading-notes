#include "../apue.3e/include/apue.h"

int main(void) {
  struct stat statbuf;
  if (stat("foo", &statbuf) < 0)
    err_sys("stat error");
  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    err_sys("chmod error");
  // Set absolute mode to "rw-r--r--"
  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    err_sys("chmod error");

  exit(0);
}