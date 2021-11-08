#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 10
#define BUFFER_LEN 2048

off_t get_pos(char* filename, int lines);

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "tail error\n");
    exit(EXIT_FAILURE);
  }

  off_t pos = get_pos(argv[1], LINE_LEN);
  if (pos == -1) {
    fprintf(stderr, "seek error\n");
    exit(EXIT_FAILURE);
  }

  int fd;
  char buf[BUFFER_LEN];

  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    fprintf(stderr, "open error\n");
    exit(EXIT_FAILURE);
  }

  lseek(fd, pos, SEEK_SET);

  while ((read(fd, buf, BUFFER_LEN)) > 0) {
    fputs(buf, stdout);
  }

  close(fd);

  exit(EXIT_SUCCESS);
}

off_t get_pos(char* filename, int lines) {
  int fd;
  int pos = -1;
  int line_end_count = 0;
  char buf[BUFFER_LEN];
  char ch;

  if ((fd = open(filename, O_RDONLY)) < 0) {
    pos = -1;
  }

  pos = lseek(fd, 0, SEEK_END);

  while (pos > 0 && line_end_count < lines) {
    int i;
    pos = pos > BUFFER_LEN ? pos - BUFFER_LEN : 0;
    lseek(fd, pos, SEEK_SET);
    if (read(fd, buf, BUFFER_LEN) < 0) {
      pos = -1;
      break;
    }

    for (i = 0; i < BUFFER_LEN; i++) {
      if (buf[i] == '\0') {
        break;
      }
      if (buf[i] == '\n') {
        line_end_count++;
      }
    }
  }

  lseek(fd, pos, SEEK_SET);

  if (line_end_count >= lines) {
    while (line_end_count >= lines && (read(fd, &ch, 1)) > 0) {
      if (ch == '\n') {
        line_end_count--;
      }
    }
    pos = lseek(fd, 0, SEEK_CUR);
  }

  close(fd);

  return pos;
}