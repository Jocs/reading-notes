#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80
void to_upper(char *);
int punct_count(const char *);

int main(void)
{
  puts("Enter some words which you want to talk to me!");
  char *strs = (char *)malloc(SIZE * sizeof(char));
  char *find;
  fgets(strs, SIZE, stdin);

  find = strchr(strs, '\n');
  if (find)
    *find = '\0';
  to_upper(strs);
  puts(strs);
  printf("The line has %d punctuation characters\n", punct_count(strs));

  return 0;
}

void to_upper(char * str) {
  while (*str) {
    *str = toupper(*str);
    str++;
  }
}

int punct_count(const char * str) {
  volatile int count = 0;
  while (*str) {
    if (ispunct(*str)) {
      count++;
    }
    str++;
  }

  return count;
}