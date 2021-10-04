// get file type and print it.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int i;
  char *pt;
  struct stat buf;

  for (i = 1; i < argc; i++)
  {
    if (lstat(argv[i], &buf) < 0)
    {
      fprintf(stderr, "Can not stat file %s\n", argv[i]);
      continue;
    }
    printf("%s is ", argv[i]);
    if (S_ISREG(buf.st_mode))
    {
      pt = "regular file";
    }
    else if (S_ISDIR(buf.st_mode))
    {
      pt = "directory";
    }
    else if (S_ISBLK(buf.st_mode))
    {
      pt = "block special";
    }
    else if (S_ISCHR(buf.st_mode))
    {
      pt = "character special";
    }
    else if (S_ISFIFO(buf.st_mode))
    {
      pt = "FIFO file";
    }
    else if (S_ISSOCK(buf.st_mode))
    {
      pt = "Socket file";
    }
    else if (S_ISLNK(buf.st_mode))
    {
      pt = "Soft link";
    }
    else
    {
      pt = "Unknown mode.";
    }
    printf("%s\n", pt);
  }
  exit(0);
}