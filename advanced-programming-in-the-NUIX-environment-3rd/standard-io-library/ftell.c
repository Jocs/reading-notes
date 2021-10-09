#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

// ftell 函数的使用。

void check(bool condition, char *func, int line) {
  if (condition)
    return;
  fprintf(stderr, "%s failed in file %s at line # %d\n", func, __FILE__, line);
  exit(EXIT_FAILURE);
}

int main(void) {
  float array[SIZE] = { 1.1, 2., 3., 4., 5. };
  float arrayB[SIZE];
  FILE *fp = fopen("test", "w+b");
  check(fp != NULL, "fopen", __LINE__);
  int write_count = fwrite(&array, sizeof(float), SIZE, fp);
  check(write_count == SIZE, "fwrite", __LINE__);
  fclose(fp);

  FILE *fpr = fopen("test", "r+b");
  check(fpr != NULL, "fopen", __LINE__);
  int read_count = fread(&arrayB, sizeof(float), SIZE, fpr);
  check(read_count == SIZE, "fread", __LINE__);
  long offset = ftell(fpr);

  printf("file position is: %ld\n", offset);
  printf("arrayB[0] is %.1f\n", arrayB[0]);

  exit(EXIT_SUCCESS);
}