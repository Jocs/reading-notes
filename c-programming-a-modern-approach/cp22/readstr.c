#include <stdio.h>
#include <stdlib.h>

int writestr(const char * restrict s, FILE * restrict stream);
char *readstr(char * restrict s, int n, FILE * restrict stream);

int main(void)
{
  FILE *fp = fopen("test.txt", "a+");
  writestr("\nhello world\n", fp);
  fclose(fp);
  FILE *fp2 = fopen("test.txt", "r");
  char s[20];
  readstr(s, 20, fp2);
  printf("%s\n", s);
  return 0;
}

char *readstr(char *restrict s, int n, FILE *restrict stream)
{
  int len = 0;
  int ch;
  while (len < n - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (len == 0 || ch == EOF) {
        return NULL;
      }
      break;
    }
    s[len++] = ch;
    if (ch == '\n') break;
  }
  s[len] = '\0';
  return s;
}

int writestr(const char * restrict s, FILE * restrict stream)
{
  while (*s != '\0') {
    if (fputc(*s, stream) == EOF) {
      return EOF;
    }
    s++;
  }
  return 0;
}

// fseek(fp, 64 * n, SEEK_SET);
// fseek(fp, -64L, SEEK_END);
// fseek(fp, 64L, SEEK_CUR);
// fseek(fp, -2 * 64, SEEK_CUR);
