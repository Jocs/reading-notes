#include <stdio.h>
#include <stdlib.h>

int find_int(const char *filename);

int main(void)
{
  int n = find_int("test.txt");
  printf("%d", n);
  return 0;
}

int find_int(const char *filename)
{
  int n;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Can not open file\n");
    return -1;
  }

  while (fscanf(fp, "%d", &n) != 1) {
    if (ferror(fp)) {
      fclose(fp);
      return -2;
    }
    if (feof(fp)) {
      fclose(fp);
      return -3;
    }
    fscanf(fp, "%*[^\n]");
  }
  fclose(fp);
  return n;
}