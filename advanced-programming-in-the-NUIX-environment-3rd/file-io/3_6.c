#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 11

int main(void) {
  int fd;
  off_t offset;
  char buf[BUF_SIZE];

  fd = open("temp.foo", O_RDWR | O_APPEND);
  if (fd < 0) {
    fprintf(stderr, "Can not open temp.foo.\n");
    exit(EXIT_FAILURE);
  }
  if ((offset = lseek(fd, -10L, SEEK_END)) < 0) {
    fprintf(stderr, "Can not seek.\n");
    exit(EXIT_FAILURE);
  }

  if (read(fd, buf, 10) != 10) {
    fprintf(stderr, "Read error.\n");
    exit(EXIT_FAILURE);
  }

  if (write(fd, "hello world", 11) != 11) {
    fprintf(stderr, "Write error: %s.\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (close(fd) < 0) {
    fprintf(stderr, "Close error.\n");
    exit(EXIT_FAILURE);
  }

  printf("Buf: %s\n", buf);

  exit(0);
}