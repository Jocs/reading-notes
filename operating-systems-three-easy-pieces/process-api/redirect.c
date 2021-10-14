#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUFSIZE 20

int main(void) {
  char buf[BUFSIZ];
  char *find;
  close(STDOUT_FILENO);
  int fd = open("out.txt", O_RDWR | O_CREAT | O_TRUNC, S_IREAD | S_IWUSR);

  while (fgets(buf, BUFSIZE, stdin) != NULL)
  {
    if ((find = strchr(buf, '\n')) != NULL) {
      *find = '\0';
    }
    write(STDOUT_FILENO, buf, strlen(buf));
  }

  printf("\n");
  close(fd);
  exit(0);
}