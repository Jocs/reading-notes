#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 20
#define COPYMODE 0644

void err_handler(char* filename);

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "cp user error\n");
    exit(EXIT_FAILURE);
  }
  int in_fd;
  int out_fd;
  int count;
  int buf[BUFFER_SIZE];

  if ((in_fd = open(argv[1], O_RDONLY)) == -1) {
    err_handler(argv[1]);
  }
  if ((out_fd = creat(argv[2], COPYMODE)) == -1) {
    err_handler(argv[2]);
  }

  while ((count = read(in_fd, buf, BUFFER_SIZE)) > 0) {
    if ((write(out_fd, buf, count)) != count) {
      err_handler(argv[2]);
    }
  }

  if (count == -1) {
    err_handler(argv[1]);
  }

  if (close(in_fd) == -1 || close(out_fd) == -1) {
    err_handler(argv[1]);
  }

  exit(EXIT_SUCCESS);
}

void err_handler(char* filename) {
  perror(filename);
  exit(EXIT_FAILURE);
}