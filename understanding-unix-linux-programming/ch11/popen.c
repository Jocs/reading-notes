#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1
#define BUFSIZE 20

FILE* my_popen(const char* command, const char* mode) {
  int pfp[2], pid;
  FILE* fp;
  int parent_end, child_end;

  if (*mode == 'r') {
    parent_end = READ;
    child_end = WRITE;
  } else if (*mode == 'w') {
    parent_end = WRITE;
    child_end = READ;
  } else {
    return NULL;
  }

  if (pipe(pfp) == -1) {
    perror("pipe");
    exit(1);
  }

  if ((pid = fork()) == -1) {
    return NULL;
  } else if (pid == 0) {
    // child process
    if (close(pfp[parent_end]) == -1) {
      perror("close");
      exit(1);
    }
    if (dup2(pfp[child_end], child_end) == -1) {
      perror("dup2");
      exit(1);
    }
    if (close(pfp[child_end]) == -1) {
      perror("close 2");
      exit(1);
    }

    execl("/bin/sh", "sh", "-c", command, NULL);
    exit(1);
  } else {
    // parent process
    if (close(pfp[child_end]) == -1) {
      return NULL;
    }


    return fdopen(pfp[parent_end], mode);
  }
}

int main(int argc, char** argv) {
  FILE* fp = my_popen(argv[1], "w");
  char buf[BUFSIZE];

  while (fgets(buf, BUFSIZE, fp) != NULL) {
    printf("%s", buf);
  }

  fclose(fp);

  exit(0);
}
