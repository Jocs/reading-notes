#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
  int i, j, k;
  for (i = strlen(s) - 1 - strlen(t); i >= 0; --i) {
    for (j = i, k = 0; t[k] != '\0' && t[k++] == s[j++] ; ++j)
      ;
    if (t[k] == '\0') {
      return i;
    }
  }

  return -1;
}

int main() {
  char source[] = "hello world";
  char dest[] = "l";
  int result = strindex(source, dest);

  printf("The result is %d\n", result);
}