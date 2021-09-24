#include <stdio.h>
#include <stdlib.h>

// 打开一个文件，输出每个字符，并且统计字符数量。
int main(int argc, char *argv[])
{
  register int ch;
  unsigned long int count = 0;
  FILE *fp;

  if (argc != 2) {
    puts("Need input the file name.");
    exit(EXIT_FAILURE);
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    puts("Can not open the file.");
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF) {
    putc(ch, stdout);
    count++;
  }

  printf("\nFile closed and return value is %d\n", fclose(fp));

  printf("\nThe file %s has %ld characters\n", argv[1], count);
  exit(EXIT_SUCCESS);
}