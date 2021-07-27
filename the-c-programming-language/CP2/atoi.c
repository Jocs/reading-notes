#include <stdio.h>

int atoi(char s[]) {
  unsigned short int i;
  unsigned int n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    n = n * 10 + (s[i] - '0');
  }

  return n;
}

char lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else {
    return c;
  }
}

int main() {
  printf("the out put is %d\n", atoi("3453289"));
  printf("the lowercase of A is %c\n", lower('A'));
}
