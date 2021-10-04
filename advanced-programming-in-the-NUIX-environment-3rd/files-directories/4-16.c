#include "../apue.3e/include/apue.h"
#include <unistd.h>
#include <fcntl.h>

int main(void) {
  if (open("foo", O_RDWR) < 0)
    err_sys("open foo error");
  puts("open foo file");
  if (unlink("foo") < 0)
    err_sys("unlink error");
  puts("unlink foo done");
  // sleep 没有效果？？？
  sleep(15);
  puts("done");
  exit(0);
}