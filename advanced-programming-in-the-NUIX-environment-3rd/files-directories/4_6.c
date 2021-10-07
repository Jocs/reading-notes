#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

static void create_hole_file(char *filename);
static void copy_file(char *filename);

int main(int argc, char *argv[]) {
  int fd;
  if (argc != 2) {
    fprintf(stderr, "usage: ./a.out <filename>\n");
    exit(EXIT_FAILURE);
  }

  create_hole_file(argv[1]);
  copy_file(argv[1]);

  exit(0);
}

void create_hole_file(char *filename) {
  int fd;
  if ((fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, RWRWRW)) < 0) {
    fprintf(stderr, "Can not open/create %s\n", filename);
    exit(EXIT_FAILURE);
  }

  if (write(fd, "HELLO WORLD", 11) != 11) {
    fprintf(stderr, "write error\n");
    exit(EXIT_FAILURE);
  }

  if (lseek(fd, 200000, SEEK_SET) == -1) {
    fprintf(stderr, "lseek error\n");
    exit(EXIT_FAILURE);
  }

  if (write(fd, "hello world", 11) != 11) {
    fprintf(stderr, "write error\n");
    exit(EXIT_FAILURE);
  }
}

void copy_file(char *filename) {
  int fd1, fd2;
  int c;
  struct stat buf;
  // TODO error handler
  fd1 = open(filename, O_RDWR);
  if (stat(filename, &buf) < 0) {
    // error handler.
  }
  printf("block size: %d, file size: %d, blocks: %d\n", (int) buf.st_blksize, (int)buf.st_size, (int) buf.st_blocks);
  fd2 = open("copy", O_RDWR | O_CREAT | O_TRUNC, RWRWRW);
  while (read(fd1, &c, 1) == 1) {
    if (c != '\0') {
      write(fd2, &c, 1);
    }
  }
}