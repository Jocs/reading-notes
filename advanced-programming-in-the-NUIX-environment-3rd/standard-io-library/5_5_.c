#include <stdio.h>
#include <stdlib.h>
// 创建文件 argv[1], 并且从标准输入获取内容。

int main(int argc, char **argv) {
  FILE *fp;
  int ch;

  if ((fp = fopen(argv[1], "w+")) == NULL) {
    puts("usage: ./a.out <filename>");
    exit(EXIT_FAILURE);
  }
  while ((ch = fgetc(stdin)) != EOF) {
    if (fputc(ch, fp) == EOF) {
      fprintf(stderr, "fputc error");
    }
  }

  fclose(fp);

  exit(EXIT_SUCCESS);
}
