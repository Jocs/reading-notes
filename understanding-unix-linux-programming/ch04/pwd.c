#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void print_path(void);
ino_t get_inode(char* path);
char* get_filename(ino_t inode);

int main(int argc, char** argv) {
  print_path();
  return 0;
}

void print_path(void) {
  ino_t  cur = get_inode(".");
  ino_t  par = get_inode("..");
  char filename[256];

  chdir("..");
  strcpy(filename, get_filename(cur));

  if (cur != par && strlen(filename) > 0) {
    print_path();
  }
  printf("/%s", filename);
}

ino_t get_inode(char* path) {
  struct stat st;
  if (stat(path, &st) == -1) {
    perror("stat");
    exit(1);
  }
  return st.st_ino;
}

char* get_filename(ino_t inode) {
  DIR* dir;
  struct dirent* ent;
  if ((dir = opendir(".")) == NULL) {
    perror("opendir");
    exit(1);
  }
  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_ino == inode) {
      closedir(dir);
      return ent->d_name;
    }
  }
  closedir(dir);

  return "";
}
