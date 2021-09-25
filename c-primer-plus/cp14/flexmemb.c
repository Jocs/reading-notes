#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5

struct flex {
  size_t count;
  double average;
  double scores[];
};

void show_flex(const struct flex *p);

int main(void) {
  struct flex *pt;
  pt = malloc(sizeof(struct flex) + LEN * sizeof(double));
  pt->count = LEN;
  int i;
  double total = 0;
  srand(time(NULL));
  for (i = 0; i < pt->count; i++)
  {
    pt->scores[i] = (double)rand() / (double) RAND_MAX * 100.00;
    total += pt->scores[i];
  }
  pt->average = total / pt->count;

  show_flex(pt);
  free(pt);
  return 0;
}

void show_flex(const struct flex *p) {
  int i = 0;
  for (; i < p->count; i++) {
    printf("%-8.2f", p->scores[i]);
  }
  printf("\n");
  printf("Average value is: %.2f\n", p->average);
}