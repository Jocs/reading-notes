#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <fcntl.h>

#define oop(m, x){perror(m);exit(x);}
#define BUFLEN 10

void lock_operation(int fd, int op);

int main(int argc, char** argv) {
  int fd;
  int n;
  int buf[BUFLEN];

  if (argc != 2) {
    oop("Usage: file_tc filename", 1);
  }
  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    oop("open", 2);
  }
  lock_operation(fd, F_RDLCK);
  while ((n = read(fd, buf, BUFSIZ)) > 0)
    write(1, buf, n);
  lock_operation(fd, F_UNLCK);
}

void lock_operation(int fd, int op) {
  struct flock lock;
  lock.l_whence = SEEK_SET;
  lock.l_start = lock.l_len = 0;
  lock.l_pid = getpid();
  lock.l_type = op;
  if (fcntl(fd, F_SETLK, &lock) == -1) {
    oop("lock operation", 6);
  }
}