#include <stdio.h>
#define STLEN 10

int main(void) {
  char words[STLEN];
  int i;
  puts("Enter strings (empty line to quit):");
  while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
    i = 0;
    while (words[i] != '\0' && words[i] != '\n')
      i++;
    if (words[i] == '\n')
      words[i] = '\0';
    else {
      while(getchar() != '\n')
        continue;
    }
    puts(words);
  }

  puts("Done.");

  return 0;
}