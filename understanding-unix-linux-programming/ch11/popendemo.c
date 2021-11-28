#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 20

int main(int argc, char** argv) {
  FILE* fp = popen(argv[1], "r");
  char buf[BUFSIZE];

  while (fgets(buf, BUFSIZE, fp) != NULL) {
    printf("%s", buf);
  }

  pclose(fp);

  exit(0);
}