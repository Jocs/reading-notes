#include <stdio.h>
#define LEN 20
struct names
{
  char first[LEN];
  char last[LEN];
};

struct guy
{
  struct names handle;
  char favfood[LEN];
  char job[LEN];
  float income;
};

int main(void) {
  struct guy fellows[2] =
  {
    {
      {"luo", "ran"},
      "salmon",
      "soft engineer",
      12.21
    },
    {
      {"wu", "jingwen"},
      "foo",
      "soft bar",
      22.21
    },
  };
  struct guy *him;
  printf("#1 %p, #2 %p\n", fellows, &fellows[1]);
  him = fellows;
  printf("#1 %p, #2 %p\n", him, him + 1);
  printf("income => %.2f, job => %s\n", him->income, (*him).job);
  him++;
  printf("income => %.2f, job => %s\n", him->income, (*him).job);
  return 0;
}
