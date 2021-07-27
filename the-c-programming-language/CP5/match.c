#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_STR_LEN 1000

char *lineptr[MAX_LINES];

int readline(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quicksort(void *linepst[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *, const char *);
void swap(void *v[], int i, int j);

int readline(char *s, int lim)
{
  int i;
  char c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    *s++ = c;
  }
  if (c == '\n') {
    i++;
    *s++ = c;
  }
  *s = '\0';
  return i;
}

int readlines(char *lines[], int maxlines)
{
  int nlines = 0, c;
  char *p, line[MAX_STR_LEN];
  while ((c = readline(line, MAX_STR_LEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(c * sizeof(char))) == NULL) {
      return -1;
    } else {
      line[c - 1] = '\0';
      strcpy(p, line);
      lines[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void quicksort(void *linepst[], int left, int right, int (*comp)(const void *, const void *))
{
  if (left >= right)
    return;
  swap(linepst, left, (left + right) / 2);
  int last = left, i;
  for (i = left + 1; i <= right; i++) {
    if ((*comp)(linepst[i], linepst[left]) < 0) {
      last++;
      swap(linepst, last, i);
    }
  }
  swap(linepst, left, last);
  quicksort(linepst, left, last - 1, comp);
  quicksort(linepst, last + 1, right, comp);
}

int numcmp(const char * s1, const char * s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  return v1 - v2;
}
void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;
  if (argc > 1 && strcmp(argv[1], "-n") == 0) {
    numeric = 1;
  }
  if ((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
    quicksort((void **) lineptr, 0, nlines - 1, (int (*)(const void *, const void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
  return 0;
}