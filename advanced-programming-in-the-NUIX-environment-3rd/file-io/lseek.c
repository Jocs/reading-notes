#include "../apue.3e/include/apue.h"

int main(void) {
  off_t offset;
  if ((offset = lseek(STDIN_FILENO, 0, SEEK_CUR)) == -1)
    fprintf(stderr, "Can not seek stdin\n");
  else
    printf("The offset is: %lld\n", offset);

  exit(0);
}