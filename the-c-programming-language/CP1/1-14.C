#include <stdio.h>

int main() {
 int c;
 int hash[128];
 int i;
 char *upper = (char *) "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char *lower = (char *) "abcdefghijklmnopqrstuvwxyz";
 while (*upper != '\0')
  {
    hash[*upper++] = 0;
  }
  while (*lower != '\0')
  {
    hash[*lower++] = 0;
  }
  while((c = getchar()) != EOF)
  {
    hash[c]++;
  }
  for (i = 0; i < 128; i++) {
    if (hash[i] && ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))) {
      printf("%c: %d\n", i, hash[i]);
    }
  }
}
