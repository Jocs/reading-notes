#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <utime.h>

#define BUFFER_SIZE 20
#define FILENAME_LEN 256
#define COPYMODE 0644

void err_handler(char* filename);
void do_copy(char* source, char* dist);

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "cp user error\n");
    exit(EXIT_FAILURE);
  }
  char source_filename[FILENAME_LEN];
  struct stat st;

  stat(argv[1], &st);

  if (S_ISDIR(st.st_mode)) {
    DIR* dir;
    struct dirent* dr;
    if ((dir = opendir(argv[1])) == NULL) {
      err_handler(argv[1]);
    }
    while ((dr = readdir(dir)) != NULL) {
      // 没有处理 folder 包含其它文件夹的 case，可以过滤或者递归复制。
      if (strcmp(dr->d_name, ".") == 0 || strcmp(dr->d_name, "..") == 0) {
        continue;
      }
      strcpy(source_filename, argv[1]);
      strcat(source_filename, "/");
      strcat(source_filename, dr->d_name);
      do_copy(source_filename, argv[2]);
    }
    closedir(dir);
  } else {
    do_copy(argv[1], argv[2]);
  }

  exit(EXIT_SUCCESS);
}

void do_copy(char* source, char* dist) {
  int in_fd;
  int out_fd;
  int count;
  int buf[BUFFER_SIZE];
  int dist_filename[FILENAME_LEN];
  struct stat st;
  struct utimbuf utbuf;

  if ((in_fd = open(source, O_RDONLY)) == -1) {
    err_handler(source);
  }

  stat(dist, &st);
  strcpy(dist_filename, dist);
  if (S_ISDIR(st.st_mode)) {
    strcat(dist_filename, "/");
    strcat(dist_filename, strstr(source, "/") ? strstr(source, "/") + 1 : source);
  }

  if ((out_fd = creat(dist_filename, COPYMODE)) == -1) {
    err_handler(dist_filename);
  }

  while ((count = read(in_fd, buf, BUFFER_SIZE)) > 0) {
    if ((write(out_fd, buf, count)) != count) {
      err_handler(dist_filename);
    }
  }

  if (count == -1) {
    err_handler(source);
  }

  if (close(in_fd) == -1 || close(out_fd) == -1) {
    err_handler(source);
  }

  if (stat(source, &st) == -1) {
    err_handler(source);
  }

  // 重设访问时间和修改时间
  utbuf.actime = st.st_atimespec.tv_sec;
  utbuf.modtime = st.st_mtimespec.tv_sec;
  utime(dist_filename, &utbuf);
}

void err_handler(char* filename) {
  perror(filename);
  exit(EXIT_FAILURE);
}