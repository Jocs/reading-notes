#include <stdio.h>
#include "names_st.h"

void get_names(names *pn) {
  printf("Please enter the first name:\n");
  s_gets(pn->first, SLEN);
  puts("Please enter the last name:");
  s_gets(pn->last, SLEN);
}

void show_names(const names *pn) {
  printf("Your full name: %s %s\n", pn->first, pn->last);
}

char *s_gets(char * st, int n) {
  char *ret_val;
  char *find;
  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');
    if (find) {
      *find = '\0';
    } else {
      while(getchar() != '\n')
        continue;
    }
  }

  return ret_val;
}