#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchFor[]);
int isSpace(char c);
int isDigit(char c);
float atof(char s[]);

char pattern[] = "ould";

int isSpace(char c)
{
  if (c == '\n' || c == '\t' || c == ' ')
  {
    return 1;
  }
  return 0;
}

int isDigit(char c)
{
  if (c >= '0' && c <= '9')
  {
    return 1;
  }
  return 0;
}

int getLine(char line[], int max)
{
  int i, c;
  i = 0;
  while (--max > 0 && (c = getchar()) != '\n') {
    line[i++] = c;
  }
  if (c == '\n') {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}

int strindex(char source[], char pattern[])
{
  int i, j, k;

  for (i = 0; source[i] != '\0'; i++) {
    for (j = i, k = 0; pattern[k] != '\0' && source[j] == pattern[k]; j++, k++ ) {
      ;
    }
    if (k > 0 && pattern[k] == '\0') {
      return i;
    }
  }
  return -1;
}

float atof(char s[])
{
  int i, sign;
  float val, power;
  for (i = 0; isSpace(s[i]); i++)
    ;
  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }
  for (val = 0.0; isDigit(s[i]); i++) {
    val = val * 10.0 + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1; isDigit(s[i]); i++) {
    val = val * 10.0 + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}

int main()
{
  char line[MAXLINE];
  char str[] = "234.236";

  int found = 0;
  // while (getLine(line, MAXLINE) != EOF) {
  //   if (strindex(line, pattern) > -1) {
  //     printf("%s", line);
  //     found++;
  //   }
  // }
  printf("%f\n", atof(str));
  return found;
}