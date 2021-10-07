#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// test feof function 

int main(void) {
  FILE *fp;
  fpos_t offset;
  int ch;
  int isEOF;
  if ((fp = fopen("test", "w+")) == NULL) {
    fprintf(stderr, "open error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  fputs("ransixi", fp);
  fgetpos(fp, &offset);
  printf("current offset is: %lld\n", offset);
  rewind(fp);
  fgetpos(fp, &offset);
  printf("current offset is: %lld, after rewind.\n", offset);
  while ((ch = fgetc(fp)) != EOF) {
    fputc(ch, stdout);
  }
  putchar('\n');
  fgetpos(fp, &offset);
  printf("current offset is: %lld, after output to stdout.\n", offset);
  isEOF = feof(fp);
  printf("is end of file %d\n", isEOF);
  fclose(fp);

  exit(EXIT_SUCCESS);
}