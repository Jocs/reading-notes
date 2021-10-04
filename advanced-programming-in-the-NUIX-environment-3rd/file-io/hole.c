#include "../apue.3e/include/apue.h"
#include <fcntl.h>

static char buf1[] = "abcdefghij";
static char buf2[] = "ABCDEFGHIJ";

int main(void)
{
  int fd;
  if ((fd = creat("file.hole", FILE_MODE)) < 0) // FILE_MODE 顶一下 apue.h 头文件中
    err_sys("creat error");

  if (write(fd, buf1, 10) != 10)
    err_sys("Write buf1 error");
  
  if (lseek(fd, 16384, SEEK_SET) == -1)
    err_sys("Seek error");
  
  if (write(fd, buf2, 10) != 10)
    err_sys("Write buf2 error");

  exit(0);
}