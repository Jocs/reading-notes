#include <stdio.h>
#include <string.h>
#include "common.h"
#define SIZE 81
#define LIM 20

void sort_str(char *string[], int num);

int main(void) {
  char strings[LIM][SIZE];
  char *pts[LIM];
  puts("Input some words.\n");
  int i;
  while (i < LIM && s_gets(strings[i], SIZE) && strings[i][0] != '\0') {
    pts[i] = strings[i];
    i++;
  }
  puts("\nHere is sorted strings.\n");
  sort_str(pts, i);
  for (i = 0; i < LIM; i++) {
    pts[i] && puts(pts[i]);
  }
  puts("\nDone!");

  return 0;
}

void sort_str(char *string[], int num) {
  int i, j;
  char *temp;
  for (i = 0; i < num - 1; i++) {
    for (j = i + 1; j < num; j++) {
      // printf("%d", strcmp(string[i], string[j]));
      if (strcmp(string[i], string[j]) > 0) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
      }
    }
  }
}
