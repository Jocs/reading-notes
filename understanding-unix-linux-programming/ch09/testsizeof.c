#include <stdlib.h>
#include <stdio.h>

int main(void) {
  printf("sizeof char * %lu\n", sizeof(char*));
  printf("sizeof char %lu\n", sizeof(char));
  printf("sizeof int * %lu\n", sizeof(int*));
  printf("sizeof int %lu\n", sizeof(int));
}