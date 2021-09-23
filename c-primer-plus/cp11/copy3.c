#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

#define SIZE 40
#define TARGSIZE 7
#define LIM 5

int main(void) {
  char words[LIM][TARGSIZE];
  char temp[SIZE];
  int i = 0;
  while (i < LIM && s_gets(temp, SIZE)) {
    if (temp[0] == 'q') {
      printf("word %s can not start with q.", temp);
    } else {
      strncpy(words[i], temp, TARGSIZE - 1);
      words[i][TARGSIZE - 1] = '\0';
      i++;
    }
  }
  for (i = 0; i < LIM; i++) {
    puts(words[i]);
  }
  exit(0);
}