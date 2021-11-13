#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <errno.h>

#define FILEPATH_LEN 256

bool start_with(const char* str, const char* prefix);
void read_dir(const char* dirname);
void show_file_info(const char* filename);
char* showname(uid_t user_id);
char* showgname(uid_t group_id);
char* showtime(const time_t time);
void tranlate_mode(int mode, char* str);

int main(int argc, char** argv) {
  int i;
  struct stat stat_buf;

  if (argc == 1) {
    read_dir(".");
  } else {
    for (i = 1; i < argc; i++) {
      if (stat(argv[i], &stat_buf) == -1) {
        continue;
      }
      if (S_ISDIR(stat_buf.st_mode)) {
        read_dir(argv[i]);
      } else {
        show_file_info(argv[i]);
      }
    }
  }

  exit(EXIT_SUCCESS);
}

void read_dir(const char* dirname) {
  DIR* dir;
  struct dirent* dir_entry;
  char filepath[FILEPATH_LEN];

  if (strcmp(dirname, ".")) {
    printf("%s:\n", dirname);
  }

  if ((dir = opendir(dirname)) == NULL) {
    fprintf(stderr, "opendir . error\n");
    exit(EXIT_FAILURE);
  }

  while ((dir_entry = readdir(dir)) != NULL) {
    strcpy(filepath, dirname);
    strcat(filepath, "/");
    strcat(filepath, dir_entry->d_name);

    if (!start_with(dir_entry->d_name, ".") && !start_with(dir_entry->d_name, "..")) {
      show_file_info(filepath);
    }
  }

  closedir(dir);
}

void show_file_info(const char* filename) {
  struct stat stat_buf;
  if (stat(filename, &stat_buf) == -1) {
    perror(filename);
    exit(EXIT_FAILURE);
  }

  char modestr[11];
  tranlate_mode(stat_buf.st_mode, modestr);
  char* index = strstr(filename, "/");

  printf("%s ", modestr);
  printf("%d ", stat_buf.st_nlink);
  printf("%s ", showname(stat_buf.st_uid));
  printf("%s ", showgname(stat_buf.st_gid));
  printf("%8lld ", stat_buf.st_size);
  printf("%15.15s ", showtime((long)stat_buf.st_mtimespec.tv_sec));
  // Only print filename.
  printf("%s\n", index != NULL ? index + 1 : filename);
}

char* showname(uid_t user_id) {
  struct passwd* ps = getpwuid(user_id);

  return ps->pw_name;
}

char* showgname(uid_t group_id) {
  struct group* gs = getgrgid(group_id);

  return gs->gr_name;
}

char* showtime(const time_t time) {
  return ctime(&time) + 4;
}

void tranlate_mode(int mode, char* str) {
  strcpy(str, "----------");
  if (S_ISDIR(mode)) {
    str[0] = 'd';
  }

  if (S_ISBLK(mode)) {
    str[0] = 'b';
  }

  if (S_ISCHR(mode)) {
    str[0] = 'c';
  }

  if (mode & S_IRUSR)
    str[1] = 'r';
  if (mode & S_IWUSR)
    str[2] = 'w';
  if (mode & S_IXUSR)
    str[3] = 'x';
  if (mode & S_IRGRP)
    str[4] = 'r';
  if (mode & S_IWGRP)
    str[5] = 'w';
  if (mode & S_IXGRP)
    str[6] = 'x';
  if (mode & S_IROTH)
    str[7] = 'r';
  if (mode & S_IWOTH)
    str[8] = 'w';
  if (mode & S_IXOTH)
    str[9] = 'x';
}

bool start_with(const char* str, const char* prefix) {
  int len_str = strlen(str);
  int len_prefix = strlen(prefix);
  int min_len = len_str > len_prefix ? len_prefix : len_str;
  int i;

  for (i = 0; i < min_len; i++) {
    if (str[i] != prefix[i]) {
      return false;
    }
  }

  return true;
}