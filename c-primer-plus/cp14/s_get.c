#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"

char *s_get(char *st, int n) {
  char *ret_val;
  char *find;
  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')
        continue;
  }

  return ret_val;
}