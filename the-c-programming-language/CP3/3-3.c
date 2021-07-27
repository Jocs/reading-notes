#include <stdio.h>

void expand(char s1[], char s2[]) {
  int c;
  int i = 0;
  int j = 0;
  int k = 0;
  int last = -1;
  int pre = -1;

  while((c = s1[i++]) != '\0') {
    if (c == '-') {
      if (last > -1) {
        pre = last;
      } else {
        s2[j++] = c;
      }
    } else {
      if (pre > -1) {
        for (k = pre + 1; k <= c; k++) {
          s2[j++] = k;
        }
        pre = -1;
      } else {
        last = c;
        s2[j++] = c;
      }
    }
  }

  if (pre > -1) {
    s2[j++] = '-';
  }

  s2[j] = '\0';
}

int main() {
  char s1[] = "-a-d0-4b-c-";
  char s2[100];
  expand(s1, s2);
  printf("%s\n", s2);
}