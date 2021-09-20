#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME_LENGTH 50

int main(void) {
  int ch;
  FILE *fp;
  char fname[FILE_NAME_LENGTH];
  printf("Please the filename which you want to open\n");
  scanf("%s", fname);

  fp = fopen(fname, "r");

  if (fp == NULL) {
    printf("Can not open the file %s", fname);
    exit(0);
  }

  while ((ch = getc(fp)) != EOF)
    putchar(ch);

  fclose(fp);

  return 0;
}