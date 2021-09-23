#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void) {
  char *name1 = (char *)malloc(SIZE * sizeof(char));
  char *name2 = (char *)malloc(SIZE * sizeof(char));

  puts("Please enter two names.");
  int count;

  if ((count = scanf("%s %s", name1, name2)) == 2) {
    printf("You input %d names, %s and %s\n", count, name1, name2);
  }

  exit(0);
}