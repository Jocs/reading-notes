#include <stdio.h>
#include <stdlib.h>

static unsigned long int next = 1;

unsigned int rand0(void);
void srand0(unsigned long int);

int main(int argc, char *argv[])
{
  int i;
  unsigned int value;
  srand0(atoi(argv[1]));
  for (i = 0; i < atoi(argv[2]); i++)
  {
    value = rand0();
    printf("random number: %d\n", value);
  }
}

unsigned int rand0(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand0(unsigned long int seed)
{
  next = seed;
}