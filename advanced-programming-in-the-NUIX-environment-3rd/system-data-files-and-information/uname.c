#include <stdlib.h>
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>
#include <errno.h>

int main(void) {
  struct utsname name;

  if (uname(&name) == -1) {
    fprintf(stderr, "uname error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("sysname: %s, nodename: %s, release: %s, version: %s, machine: %s\n", name.sysname, name.nodename, name.release, name.version, name.machine);
  exit(0);
}