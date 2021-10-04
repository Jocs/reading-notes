#include "../apue.3e/include/apue.h"

int main(void) {
  char *pt;
  size_t size;
  if (chdir("/tmp") < 0)
    err_sys("change dir failed");
  printf("chdir to /tmp successed\n");
  pt = path_alloc(&size);
  if (getcwd(pt, size) == NULL)
    err_sys("getcwd failed");
  printf("cwd = %s\n", pt);
  exit(0);
}