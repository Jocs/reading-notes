#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000L
#define MIN 100000L

long get_long(void);
double sum_square(long start, long end);
bool bad_limit(long start, long end, long low, long high);

int main(void) {
  long start, stop;
  double total;
  printf("Please enter start and stop number\n");
  printf("Enter start\n");
  start = get_long();
  printf("Enter end\n");
  stop = get_long();
  while (start != 0 && stop != 0)
  {
    while (getchar() != '\n')
      continue;
    if (bad_limit(start, stop, MIN, MAX)) {
      printf("bad input\n");
      break;
    }
    total = sum_square(start, stop);
    printf("The total is %.2f from %ld to %ld\n", total, start, stop);
    printf("Please enter start and stop number, Both 0 to quit\n");
    printf("Enter start\n");
    start = get_long();
    printf("Enter end\n");
    stop = get_long();
  }

  printf("Done!\n");

  return 0;
}

long get_long(void) {
  long result;
  while (scanf("%ld", &result) != 1) {
    while (getchar() != '\n')
      continue;
    printf("Enter a long integer like 4, 456\n");
  }

  return result;
}

double sum_square(long start, long end) {
  long i;
  double total = 0;
  for (i = start; i <= end; i++) {
    total += (double)i * (double)i;
  }

  return total;
}

bool bad_limit(long start, long end, long low, long high) {
  bool is_valid = true;
  if (start > end) {
    is_valid = false;
  }

  if (start < low || end < low) {
    is_valid = false;
  }

  if (start > high || end > high) {
    is_valid = false;
  }

  return is_valid;
}