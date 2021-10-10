#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2) {
    fprintf(stderr, "usage: %s dir_name\n", argv[0]);
    exit(1);
  }

  if ((dp = opendir(argv[1])) == NULL) {
    fprintf(stderr, "can not open %s\n", argv[1]);
    exit(1);
  }

  while ((dirp = readdir(dp)) != NULL) {
    printf("%s %d\n", dirp->d_name, dirp->d_type);
  }

  closedir(dp);

  exit(0);
}