#include <stdio.h>

#define MAX_LINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAX_LINE];
  char longest[MAX_LINE];

  max = 0;

  while ((len = getLine(line, MAX_LINE)) > 0) {
    if (len > max) {
      copy(longest, line);
      max = len;
    }
  }
  if (max > 0) {
    printf("%s", longest);
  }
  return 0;
}

int getLine(char s[], int lim)
{
  int i, c;
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}