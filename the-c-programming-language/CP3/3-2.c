#include <stdio.h>

void escape(char s[], char t[]) {
  int c;
  int i = 0;
  int j = 0;
  while((c = t[j++]) != '\0') {
    switch (c) {
      case '\n':
        s[i++] = '\\';
        s[i++] = 'n';
        break;
      case '\t':
        s[i++] = '\\';
        s[i++] = 't';
        break;
      default:
        s[i++] = c;
        break;
    }
  }
  s[i] = '\0';
}

int main() {
  char str1[] = "Hello world\nThis is text line\tThe is text line.";
  char str2[100];
  escape(str2, str1);

  printf("%s\n", str2);
}