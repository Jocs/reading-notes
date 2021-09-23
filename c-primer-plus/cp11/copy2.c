#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40

int main(void) {
  const char *orig = WORDS;
  char copy[SIZE] = "Be the best that you can be.";
  char *pt;
  puts(orig);
  puts(copy);
  pt = strcpy(copy + 7, orig); // 不一定是字符串的初始位置.
  puts(copy);
  puts(pt);

  return 0;
}