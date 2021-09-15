#include "../apue.3e/include/apue.h"

int main() {
  printf("user id: %d, group id: %d\n", (int)getuid(), (int)getgid());
  exit(0);
}