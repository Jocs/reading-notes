#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 11
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

int getch(void);
void ungetch(int c);
int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void)
{
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    // printf("%s\n", word);
    if (isalpha(word[0]))
      if ((n = binsearch(word, keytab, NKEYS)) >= 0)
        keytab[n].count++;
  }
  for (n = 0; n < NKEYS; n++)
    if (keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
  int cond, low, high, middle;
  low  = 0;
  high = n - 1;
  while (low <= high) {
    middle = (low + high) / 2;
    if ((cond = strcmp(word, tab[middle].word)) > 0) {
      low = middle + 1;
    } else if (cond < 0) {
      high = middle - 1;
    } else {
      return middle;
    }
  }
  return -1;
}

int getch(void) {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: you input too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}

int getword(char *word, int lim)
{
  int c;
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++) {
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}