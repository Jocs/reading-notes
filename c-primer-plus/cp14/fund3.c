#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50

struct funds
{
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};

double sum(const struct funds);

int main(void) {
  struct funds ransixi = {
    "Zhong guo ren min yin hang.",
    1000.2,
    "Lucky's savings and loan",
    123.45
  };
  printf("The sum is %.2f\n", sum(ransixi));

  exit(0);
}

double sum(const struct funds r) {
  return r.bankfund + r.savefund;
}
