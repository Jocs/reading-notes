#include <stdio.h>

#define MEMORYSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000

char *linepstr[MAXLINES];

static char allocbuf[MEMORYSIZE];
static char *allobufp = allocbuf;

int readlines(char *linepstr[], int maxlines);
void writelines(char *linepstr[], int nlines);
void qsort(char *linepstr[], int left, int right);
int strcmpa(char *s, char *t);
int getl(char *s, int lim);
char *alloc(int n);
void swap(char *v[], int i, int j);
void strcopy(char *s, char *t);

void strcopy(char *s, char *t)
{
  while ((*s = *t) != '\0')
  {
    s++;
    t++;
  }
}

void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int getl(char *s, int lim){
  int i, c;
  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int readlines(char *linepstr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getl(line, MAXLEN)) > 0) {
    if (nlines > maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcopy(p, line);
      linepstr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *linepstr[], int nlines)
{
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", linepstr[i]);
}

void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmpa(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
  }
}

int strcmpa(char *s, char *t)
{
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

char *alloc(int n)
{
  if (allocbuf + MEMORYSIZE - allobufp > n)
  {
    allobufp += n;
    return allobufp - n;
  }
  return 0;
}

void afree(char *p)
{
  if (p >= allocbuf && p < allocbuf + MEMORYSIZE) {
    allobufp = p;
  }
}

int main()
{
  int nlines;
  if ((nlines = readlines(linepstr, MAXLINES)) >= 0) {
    qsort(linepstr, 0, nlines - 1);
    writelines(linepstr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return -1;
  }
}