#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("need add arg\n");
    exit(EXIT_FAILURE);
  }
  int num = atoi(argv[1]);
  int numbers[num];

  for (int i = 0; i < num; i++) {
    numbers[i] = num - i;
  }
  clock_t start = clock();
  qsort(numbers, num, sizeof(numbers[0]), compare);
  printf("time: %g\n", (clock() - start) / (double)CLOCKS_PER_SEC);
  return 0;
}