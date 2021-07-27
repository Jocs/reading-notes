#include<stdio.h>

int isInStr(int a, char s[]) {
  int i = 0;
  int c;
  while ((c = s[i++]) != '\0') {
    if (c == a) {
      return 1;
    }
  }
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (!isInStr(s1[i], s2)) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int any(char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  int c;
  while ((c = s2[i++]) != '\0') {
    if (isInStr(c, s1)) {
      while(s1[j++] != c){}
      return --j;
    }
  }
  return -1;
}

int main() {
  char s1[] = "hello world";
  char s2[] = "leo";
  squeeze(s1, s2);
  printf("%s\n", s1);
  char s3[] = "hello world";
  char s4[] = "leo";
  int result = any(s3, s4);
  printf("The position is: %d\n", result);
}